import time
import ctypes
import os
import subprocess
import win32gui
import win32api
import win32con
import struct

# Configuration
MGBA_PATH = r"C:\PassionProjects\GBAEmu\PokemonQuetzal\mgba_src\build\mGBA.exe"
ROM_PATH = r"C:\PassionProjects\GBAEmu\PokemonQuetzal\Pokemon Quetzal.gba"
STREAM_BASE = "multi_stream"

def find_mgba_windows():
    windows = []
    def enum_handler(hwnd, lparam):
        title = win32gui.GetWindowText(hwnd)
        class_name = win32gui.GetClassName(hwnd)
        # mGBA Qt windows usually have "mGBA" in title or use Qt class name
        if "mGBA" in title or "Qt5" in class_name:
            if "mGBA" in title: # Only add if it's likely an mGBA window
                windows.append(hwnd)
                print(f"Found Window: HWND={hwnd}, Title='{title}', Class='{class_name}'")
    win32gui.EnumWindows(enum_handler, None)
    return windows

def send_rom_load(hwnd, rom_path):
    COPYDATA_ID = 0x47424101
    path_bytes = rom_path.encode('utf-16-le') + b'\x00\x00'
    
    class COPYDATASTRUCT(ctypes.Structure):
        _fields_ = [
            ('dwData', ctypes.c_ulong),
            ('cbData', ctypes.c_uint),
            ('lpData', ctypes.c_void_p)
        ]
    
    cds = COPYDATASTRUCT()
    cds.dwData = COPYDATA_ID
    cds.cbData = len(path_bytes)
    cds.lpData = ctypes.cast(ctypes.create_string_buffer(path_bytes), ctypes.c_void_p)
    
    print(f"Sending ROM load request to HWND {hwnd} for: {rom_path}")
    win32gui.SendMessage(hwnd, win32con.WM_COPYDATA, 0, ctypes.addressof(cds))

def check_pipes():
    found = []
    # Check for non-indexed base pipe
    if os.path.exists(f"\\\\.\\pipe\\{STREAM_BASE}"):
        found.append(f"\\\\.\\pipe\\{STREAM_BASE}")
    # Check for indexed pipes
    for i in range(8):
        pipe_path = f"\\\\.\\pipe\\{STREAM_BASE}_{i}"
        if os.path.exists(pipe_path):
            found.append(pipe_path)
    return found

def main():
    if not os.path.exists(MGBA_PATH):
        print(f"Error: {MGBA_PATH} not found.")
        return

    # 1. Start mGBA
    cmd = [MGBA_PATH, "-m", "4", "--stream-pipe", STREAM_BASE]
    print(f"Starting mGBA: {' '.join(cmd)}")
    proc = subprocess.Popen(cmd)
    
    try:
        print("Waiting 20 seconds for windows to spawn...")
        time.sleep(20)
        
        # 2. Verify windows spawned
        windows = find_mgba_windows()
        print(f"Found {len(windows)} mGBA windows: {windows}")
        
        # 3. Verify no pipes yet
        initial_pipes = check_pipes()
        if initial_pipes:
            print(f"Warning: Pipes already exist! {initial_pipes}")
        else:
            print("Initial check: No pipes exist (Correct for standby).")

        # 4. Inject ROM into ALL windows to ensure we hit a standby one
        if windows:
            for hwnd in windows:
                send_rom_load(hwnd, ROM_PATH)
            
            print("Waiting 10 seconds for load and pipe creation...")
            time.sleep(10)
            
            # 5. Verify pipes created
            post_pipes = check_pipes()
            if post_pipes:
                print(f"SUCCESS: Pipes created on-demand: {post_pipes}")
            else:
                print("FAILURE: No pipes were created after ROM injection.")

    finally:
        print("Terminating mGBA...")
        os.system("taskkill /f /im mGBA.exe >nul 2>&1")

if __name__ == "__main__":
    main()
