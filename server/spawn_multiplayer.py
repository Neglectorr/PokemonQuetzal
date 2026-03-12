import sys
import time
import keyboard
import logging
import win32gui
import win32con
import win32process
import psutil
from pywinauto import Application
from pywinauto.keyboard import send_keys

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

def force_focus(hwnd, expected_pid=None):
    """
    Tries to bring window to foreground and verifies it's actually focused.
    """
    try:
        if not win32gui.IsWindow(hwnd):
            return False

        # Basic Restore/Show
        if win32gui.IsIconic(hwnd):
            win32gui.ShowWindow(hwnd, win32con.SW_RESTORE)
        else:
            win32gui.ShowWindow(hwnd, win32con.SW_SHOW)
        
        # Bring to front
        try:
            win32gui.SetForegroundWindow(hwnd)
        except Exception as e:
            logging.debug(f"SetForegroundWindow failed: {e}")
            time.sleep(0.1)
            try: win32gui.SetForegroundWindow(hwnd)
            except: pass
        
        # Wait for focus with timeout
        for _ in range(15):
            curr_hwnd = win32gui.GetForegroundWindow()
            if curr_hwnd == hwnd:
                if expected_pid:
                    _, pid = win32process.GetWindowThreadProcessId(curr_hwnd)
                    if pid == expected_pid:
                        return True
                else:
                    return True
            time.sleep(0.1)
        
        return False
    except Exception as e:
        logging.warning(f"force_focus failed: {e}")
        return False

def safe_send_keys(hwnd, keys, expected_pid):
    """
    Sends keys only if the target window is still in focus.
    """
    if force_focus(hwnd, expected_pid):
        send_keys(keys)
        return True
    else:
        logging.error(f"SAFETY ABORT: Target window {hwnd} lost focus! Refusing to send keys '{keys}'.")
        return False

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
        
        # Use safe wrapper for shortcut
        if not safe_send_keys(parent_hwnd, '^m', pid):
            break
        
        # Increase timing: wait for linking and window initialization
        time.sleep(4.0) 
    
    # Ensure all menus are closed before ROM loading
    for h in get_hwnds_for_pid(pid):
        safe_send_keys(h, '{ESC}{ESC}', pid)
        time.sleep(0.1)

    # 3. Target windows for ROM loading
    # Sort: parent first, then others by creation (handle)
    all_hwnds_raw = get_hwnds_for_pid(pid)
    all_hwnds = sorted(all_hwnds_raw, key=lambda h: (0 if h == parent_hwnd else 1, h))
    
    if len(all_hwnds) < target_count:
        logging.error(f"Initialization failed: Only {len(all_hwnds)} windows available.")
    
    for i, rom_path in enumerate(rom_paths):
        if i >= len(all_hwnds): break
        target_hwnd = all_hwnds[i]
        player_num = i + 1
        logging.info(f"--- Loading Player {player_num} (HWND: {target_hwnd}) ---")
        
        # Verify focus before starting the sequence
        if not force_focus(target_hwnd, pid):
            logging.error(f"SAFETY ABORT: Failed to focus window for Player {player_num}. Skipping.")
            continue

        time.sleep(0.5)
        # Ctrl+O to open ROM dialog
        if not safe_send_keys(target_hwnd, '^o', pid):
            continue
        
        logging.info("Waiting 1.5s for dialog...")
        time.sleep(1.5)
        
        # We assume the dialog has focus now. 
        # mGBA dialogs are owned by the same PID.
        # To be extra safe, we check if the foreground window STILL belongs to our PID
        curr_hwnd = win32gui.GetForegroundWindow()
        _, curr_pid = win32process.GetWindowThreadProcessId(curr_hwnd)
        if curr_pid != pid:
            logging.error(f"SAFETY ABORT: Focus moved to PID {curr_pid} during ROM load! Aborting type.")
            continue

        # Type the path and hit Enter
        logging.info(f"Typing ROM path: {rom_path}")
        keyboard.write(rom_path)
        time.sleep(0.5)
        send_keys('{ENTER}')
            
        time.sleep(4.0) # Wait for game to load

        # 4. Mute logic
        if player_num in mute_indexes:
            logging.info(f"Muting Player {player_num}...")
            # Alt+A (menu), then 'm' (mute)
            if safe_send_keys(target_hwnd, '%am', pid):
                time.sleep(0.5)
                safe_send_keys(target_hwnd, '{ESC}{ESC}', pid)

    logging.info("Multiplayer sequence complete.")

if __name__ == '__main__':
    if len(sys.argv) < 2:
        sys.exit(1)
    target_pid = int(sys.argv[1])
    target_roms = sys.argv[2:]
    default_mute = [2, 3, 4] # Player 1 is audible for loopback
    spawn_multiplayer(target_pid, target_roms, default_mute)

