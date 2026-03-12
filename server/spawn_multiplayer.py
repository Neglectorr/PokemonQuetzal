import sys
import time
import keyboard
import logging
import win32gui
import win32con
import win32process
import win32api
import psutil

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
    Sends a key to a window using PostMessage.
    """
    scan_code = win32api.MapVirtualKey(vk, 0)
    lParam = 0x0001 | (scan_code << 16)
    if not is_down:
        lParam |= (1 << 30) | (1 << 31)
        msg = win32con.WM_KEYUP
    else:
        msg = win32con.WM_KEYDOWN
    win32api.PostMessage(hwnd, msg, vk, lParam)

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
        
        # Trigger "New multiplayer window" via F12 shortcut
        blind_key(parent_hwnd, win32con.VK_F12, True)
        time.sleep(0.05)
        blind_key(parent_hwnd, win32con.VK_F12, False)
        
        time.sleep(4.0) # Wait for linking and window initialization
    
    # Ensure all menus are closed before ROM loading
    for h in get_hwnds_for_pid(pid):
        blind_send_esc(h)
        time.sleep(0.1)

    # 3. Target windows for ROM loading
    # Sort: parent first, then others by creation (handle)
    all_hwnds = sorted(get_hwnds_for_pid(pid))
    
    if len(all_hwnds) < target_count:
        logging.error(f"Initialization failed: Only {len(all_hwnds)} windows available.")
    
    for i, rom_path in enumerate(rom_paths):
        if i >= len(all_hwnds): break
        target_hwnd = all_hwnds[i]
        player_num = i + 1
        logging.info(f"--- Loading Player {player_num} (HWND: {target_hwnd}) ---")
        
        # Trigger "Open ROM" via F11 shortcut
        blind_key(target_hwnd, win32con.VK_F11, True)
        time.sleep(0.05)
        blind_key(target_hwnd, win32con.VK_F11, False)
        
        logging.info("Waiting 2.5s for dialog...")
        time.sleep(2.5)
        
        # In Session 0 / Blind mode, we just type into the target_hwnd.
        logging.info(f"Typing ROM path: {rom_path}")
        blind_type_string(target_hwnd, rom_path)
            
        time.sleep(4.0) # Wait for game to load

        # 4. Mute logic
        if player_num in mute_indexes:
            logging.info(f"Muting Player {player_num}...")
            blind_command(target_hwnd, cmd_mute)
            time.sleep(0.5)
            blind_send_esc(target_hwnd)

    logging.info("Multiplayer sequence complete.")

if __name__ == '__main__':
    if len(sys.argv) < 2:
        sys.exit(1)
    target_pid = int(sys.argv[1])
    # Fix: target_roms is a list, and we need to pass it as such
    target_roms = sys.argv[2:]
    default_mute = [2, 3, 4] # Player 1 is audible for loopback
    spawn_multiplayer(target_pid, target_roms, default_mute)
