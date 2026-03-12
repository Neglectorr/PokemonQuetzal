import sys
import time
import logging
import win32gui
import win32con
import win32process
import win32api
import psutil
from pywinauto.application import Application
import re

def find_hwnds_by_title(title_regex):
    hwnds = []
    def cb(h, _):
        if re.match(title_regex, win32gui.GetWindowText(h)):
            hwnds.append(h)
        return True
    win32gui.EnumWindows(cb, None)
    return hwnds

logging.basicConfig(level=logging.INFO, format='%(asctime)s - %(message)s')

def get_hwnds_for_pid(pid):
    def callback(hwnd, hwnds):
        # On some server environments, IsWindowVisible can be unreliable or windows 
        # might be reported as invisible initially. We check dimensions instead.
        _, found_pid = win32process.GetWindowThreadProcessId(hwnd)
        if found_pid == pid:
            class_name = win32gui.GetClassName(hwnd)
            title = win32gui.GetWindowText(hwnd).lower()
            rect = win32gui.GetClientRect(hwnd)
            w, h = rect[2] - rect[0], rect[3] - rect[1]
            
            # Look for typical Qt/mGBA characteristics but be more lenient
            is_mgba = ("qt" in class_name.lower()) or ("mgba" in title) or (title == "")
            
            if is_mgba and w > 100 and h > 100:
                logging.info(f"Found mGBA window candidate: HWND {hwnd}, Class {class_name}, Title '{title}', Size {w}x{h}")
                hwnds.append(hwnd)
            else:
                logging.debug(f"Ignoring window for PID {pid}: HWND {hwnd}, Class {class_name}, Title '{title}', Size {w}x{h}")
        return True
    hwnds = []
    win32gui.EnumWindows(callback, hwnds)
    return hwnds

def blind_key(hwnd, vk, is_down=True):
    """
    Sends a key to a window using PostMessage with robust flags.
    """
    scan_code = win32api.MapVirtualKey(vk, 0)
    # Build a more standard lParam
    # Bits 0-15: Repeat count (1)
    # Bits 16-23: Scan code
    # Bit 24: Extended (0)
    # Bit 29: Context code (0 for most keys, but let's keep it 0)
    lParam = 0x0001 | (scan_code << 16)
    
    if not is_down:
        lParam |= (1 << 30) | (1 << 31)
        msg = win32con.WM_KEYUP
    else:
        msg = win32con.WM_KEYDOWN
    
    win32api.PostMessage(hwnd, msg, vk, lParam)
    # Also send WM_CHAR for some apps if it's a character key, 
    # but for F-keys skip it.

def blind_type_string(hwnd, text):
    """
    Types a string into a window using WM_CHAR.
    """
    for char in text:
        win32api.PostMessage(hwnd, win32con.WM_CHAR, ord(char), 0)
        time.sleep(0.01)
    # Send Enter
    blind_key(hwnd, win32con.VK_RETURN, True)
    time.sleep(0.05)
    blind_key(hwnd, win32con.VK_RETURN, False)

def blind_send_esc(hwnd):
    """
    Sends ESC key to clear menus.
    """
    blind_key(hwnd, win32con.VK_ESCAPE, True)
    time.sleep(0.05)
    blind_key(hwnd, win32con.VK_ESCAPE, False)


def spawn_multiplayer(pid, rom_paths, mute_indexes):
    # 0. Strict Process Verification
    try:
        proc = psutil.Process(pid)
        if "mgba" not in proc.name().lower():
            logging.error(f"ABORT: PID {pid} is NOT mGBA! Found process name: {proc.name()}")
            return
    except psutil.NoSuchProcess:
        logging.error(f"ABORT: Process with PID {pid} not found.")
        return

    logging.info(f"Connecting to mGBA PID {pid} (Verified)...")
    time.sleep(4) # Wait for initial GUI to be responsive
    
    # 1. Identify Parent Window
    parent_hwnds = []
    for _ in range(10): # retry for up to 5 seconds
        parent_hwnds = get_hwnds_for_pid(pid)
        if parent_hwnds:
            break
        time.sleep(0.5)

    if not parent_hwnds:
        logging.error(f"ABORT: No mGBA windows found for PID {pid} after 5s!")
        return
    
    parent_hwnd = parent_hwnds[0]
    logging.info(f"Primary Parent HWND: {parent_hwnd}")
    
    # 2. Spawn windows total
    target_count = len(rom_paths)
    attempts = 0
    while attempts < 10:
        current_hwnds = get_hwnds_for_pid(pid)
        logging.info(f"Verification: Have {len(current_hwnds)} windows, target {target_count}")
        if len(current_hwnds) >= target_count:
            break
            
        attempts += 1
        logging.info(f"Spawning window {len(current_hwnds)+1} (Attempt {attempts})...")
        
        # Trigger "New multiplayer window" via robust UIA interaction
        try:
            app = Application(backend="uia").connect(process=pid, timeout=5)
            # Find the main window that isn't a secondary one
            # mGBA main window titles are usually "mgba - 0.10.3"
            main_win = app.window(title_re=".*mGBA.*", handle=parent_hwnd)
            main_win.menu_select("File->New multiplayer window")
            logging.info("UIA: Successfully triggered 'New multiplayer window'")
        except Exception as e:
            logging.warning(f"UIA automation failed: {e}. Falling back to F12...")
            # Fallback to F12 shortcut
            blind_key(parent_hwnd, win32con.VK_F12, True)
            time.sleep(0.05)
            blind_key(parent_hwnd, win32con.VK_F12, False)
        
        time.sleep(4.0) # Wait for linking and window initialization
    
    # Ensure all menus are closed before ROM loading
    for h in get_hwnds_for_pid(pid):
        blind_send_esc(h)
        time.sleep(0.1)

    # 4. Final Verification
    all_hwnds = get_hwnds_for_pid(pid)
    logging.info(f"Multiplayer sequence complete. {len(all_hwnds)} windows available.")
    
    # 5. Load ROMs into each window
    # We skip Parent window for loading if it's already running? 
    # Actually mGBA multiplayer windows are all distinct for ROM loading.
    for i, rom_path in enumerate(rom_paths):
        if i >= len(all_hwnds): break
        target_hwnd = all_hwnds[i]
        player_num = i + 1
        logging.info(f"--- Loading Player {player_num} (HWND: {target_hwnd}) ---")
        
        try:
            # Trigger "Open ROM" dialog
            # Send to the specific window handle
            blind_key(target_hwnd, win32con.VK_F11, True)
            time.sleep(0.05)
            blind_key(target_hwnd, win32con.VK_F11, False)
            
            # 1. Handle "Select ROM" Dialog
            logging.info("Waiting for 'Select ROM' dialog...")
            dialog_hwnd = None
            for _ in range(20): # 10 seconds
                hwnds = find_hwnds_by_title(".*Select ROM.*")
                for h in hwnds:
                    _, p = win32process.GetWindowThreadProcessId(h)
                    if p == pid:
                        dialog_hwnd = h
                        break
                if dialog_hwnd: break
                time.sleep(0.5)
            
            if not dialog_hwnd:
                raise Exception("Could not find 'Select ROM' dialog.")
            
            logging.info(f"Found 'Select ROM' dialog (HWND: {dialog_hwnd}). Typing path...")
            # Use blind_type_string which is already implemented and uses PostMessage
            blind_type_string(dialog_hwnd, rom_path)
            time.sleep(0.5)
            win32api.PostMessage(dialog_hwnd, win32con.WM_KEYDOWN, win32con.VK_RETURN, 0)
            time.sleep(0.05)
            win32api.PostMessage(dialog_hwnd, win32con.WM_KEYUP, win32con.VK_RETURN, 0)
            
            # 2. Aggressively handle follow-up "Select patch"
            logging.info("Checking for 'Select patch' dialog...")
            patch_found = False
            for _ in range(10): # 5 seconds
                hwnds = find_hwnds_by_title(".*Select patch.*")
                for h in hwnds:
                    _, p = win32process.GetWindowThreadProcessId(h)
                    if p == pid:
                        logging.info("Dismissing 'Select patch' via ESC...")
                        blind_key(h, win32con.VK_ESCAPE, True)
                        time.sleep(0.05)
                        blind_key(h, win32con.VK_ESCAPE, False)
                        patch_found = True
                        break
                if patch_found: break
                time.sleep(0.5)
            
            if not patch_found: logging.info("No patch dialog detected.")
            logging.info(f"Successfully initiated load for Player {player_num}")
                
        except Exception as e:
            logging.error(f"Failed to load ROM for Player {player_num}: {e}")
            logging.info("Falling back to full blind injection on main window...")
            blind_key(target_hwnd, win32con.VK_F11, True)
            time.sleep(0.1)
            blind_key(target_hwnd, win32con.VK_F11, False)
            time.sleep(1.5)
            blind_type_string(target_hwnd, rom_path)
            time.sleep(0.5)
            blind_key(target_hwnd, win32con.VK_RETURN, True)
            time.sleep(0.05)
            blind_key(target_hwnd, win32con.VK_RETURN, False)
            
        time.sleep(2.0)

        # Mute logic is disabled for now as it requires a reliable shortcut/ID
        # in different mGBA versions.

    logging.info("Multiplayer sequence complete.")

if __name__ == '__main__':
    if len(sys.argv) < 2:
        sys.exit(1)
    target_pid = int(sys.argv[1])
    target_roms = sys.argv[2:]
    default_mute = [2, 3, 4] # Player 1 is audible for loopback
    spawn_multiplayer(target_pid, target_roms, default_mute)
