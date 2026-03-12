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
        if win32gui.IsWindowVisible(hwnd):
            _, found_pid = win32process.GetWindowThreadProcessId(hwnd)
            if found_pid == pid:
                # Filter by Window Class (mGBA uses Qt)
                class_name = win32gui.GetClassName(hwnd)
                title = win32gui.GetWindowText(hwnd).lower()
                
                # mGBA windows typically have "Qt" in the class name
                # and "mgba" in the title. We must be STRICT.
                is_mgba_class = "Qt" in class_name
                is_mgba_title = "mgba" in title or title == "mgba" or title == ""
                
                # Double check: if it's the primary window, it MUST have mGBA in title or class
                if is_mgba_class and is_mgba_title:
                    rect = win32gui.GetClientRect(hwnd)
                    # Ignore tiny/hidden-but-visible utility windows
                    if (rect[2] - rect[0]) > 200 and (rect[3] - rect[1]) > 200:
                        logging.info(f"Identified mGBA window: HWND {hwnd}, Class {class_name}, Title '{title}'")
                        hwnds.append(hwnd)
                    else:
                        logging.debug(f"Ignoring small window: {hwnd}, Rect {rect}")
                else:
                    logging.debug(f"Ignoring non-mGBA candidate: {hwnd}, Class {class_name}, Title '{title}'")
        return True
    hwnds = []
    win32gui.EnumWindows(callback, hwnds)
    return hwnds

def force_focus(hwnd, expected_pid=None):
    """
    Tries to bring window to foreground and verifies it's actually focused.
    Uses more aggressive methods to bypass Windows focus stealing restrictions.
    """
    try:
        # 1. Basic Restore/Show
        if win32gui.IsIconic(hwnd):
            win32gui.ShowWindow(hwnd, win32con.SW_RESTORE)
        else:
            win32gui.ShowWindow(hwnd, win32con.SW_SHOW)
        
        # 2. Try the Alt-key trick to trick Windows into allowing focus change
        # (This helps when the script process isn't the foreground process)
        import win32com.client
        try:
            shell = win32com.client.Dispatch("WScript.Shell")
            shell.SendKeys('%') # Send Alt
        except:
            pass

        # 3. Bring to front
        try:
            win32gui.SetForegroundWindow(hwnd)
        except Exception as e:
            logging.debug(f"SetForegroundWindow failed: {e}")
            # Try a second time after a tiny sleep
            time.sleep(0.1)
            try: win32gui.SetForegroundWindow(hwnd)
            except: pass
        
        # 4. Wait for focus with timeout
        for _ in range(15):
            curr_hwnd = win32gui.GetForegroundWindow()
            if curr_hwnd == hwnd:
                # Extra check: ensure it belongs to the right process
                if expected_pid:
                    _, pid = win32process.GetWindowThreadProcessId(curr_hwnd)
                    if pid == expected_pid:
                        return True
                else:
                    return True
            
            # Alternative: check if the focus is on a child/dialog of the window
            # but usually hwnd is what we want.
            
            time.sleep(0.1)
        
        logging.warning(f"force_focus: Window {hwnd} failed to gain focus after 1.5s")
        return False
    except Exception as e:
        logging.warning(f"force_focus failed for {hwnd}: {e}")
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
    time.sleep(2) # Wait for initial GUI
    
    app = Application(backend="uia").connect(process=pid)
    
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
        
        # Ensure we have focus before sending Ctrl+M
        if not force_focus(parent_hwnd, expected_pid=pid):
            logging.error("Failed to focus parent window. Aborting key send to prevent misclicks.")
            continue

        # Use Ctrl+M (as bound by user) for "New multiplayer window"
        send_keys('^m')
        
        # Increase timing: wait for linking and window initialization
        time.sleep(4.0) 
    
    # Ensure all menus are closed before ROM loading
    for h in get_hwnds_for_pid(pid):
        if force_focus(h, expected_pid=pid):
            send_keys('{ESC}{ESC}') # Clear any lingering menus
            time.sleep(0.2)

    # 3. Target windows for ROM loading
    # Sort: parent first, then others by creation (handle)
    all_hwnds_raw = get_hwnds_for_pid(pid)
    all_hwnds = sorted(all_hwnds_raw, key=lambda h: (0 if h == parent_hwnd else 1, h))
    
    if len(all_hwnds) < target_count:
        logging.error(f"Initialization failed: Only {len(all_hwnds)} windows available.")
    
    for i, rom_path in enumerate(rom_paths):
        if i >= len(all_hwnds): break
        target_hwnd = all_hwnds[i]
        logging.info(f"--- Loading Player {i+1} (HWND: {target_hwnd}) ---")
        
        # Ensure target window is focused
        if not force_focus(target_hwnd, expected_pid=pid):
            logging.error(f"Failed to focus window for Player {i+1}. Skipping ROM load.")
            continue

        time.sleep(0.5)
        send_keys('^o') # Ctrl+O to open ROM dialog
        
        # Wait for dialog to open and focus the filename field (auto-focused in mGBA)
        logging.info("Waiting 1.5s for dialog...")
        time.sleep(1.5)
        
        # Type the path and hit Enter
        logging.info(f"Typing ROM path: {rom_path}")
        keyboard.write(rom_path)
        time.sleep(0.5)
        send_keys('{ENTER}')
            
        time.sleep(4.0) # Wait for game to load

        # 4. Mute logic
        if (i+1) in mute_indexes:
            logging.info(f"Muting Player {i+1}...")
            if force_focus(target_hwnd, expected_pid=pid):
                send_keys('%a') # Audio/Video menu
                time.sleep(1.0) # wait for menu
                send_keys('m') # Mute hotkey
                time.sleep(1.0)
                send_keys('{ESC}{ESC}') # Ensure menu is closed

    logging.info("Multiplayer sequence complete.")

if __name__ == '__main__':
    if len(sys.argv) < 2:
        sys.exit(1)
    pid = int(sys.argv[1])
    roms = sys.argv[2:]
    mute_indexes = [2, 3, 4] # Player 1 is audible for loopback
    spawn_multiplayer(pid, roms, mute_indexes)

