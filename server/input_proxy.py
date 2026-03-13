import sys
import os
import time
import win32gui
import win32api
import win32con
import psutil

# GBA Key Map to mGBA Defaults (mGBA keys are just scan codes or virtual keys)
# Default mGBA keys (Standard Layout):
# Up: Up, Down: Down, Left: Left, Right: Right
# A: X, B: Z, L: A, R: S, Start: Enter, Select: Backspace
KEY_MAP = {
    "UP": win32con.VK_UP,
    "DOWN": win32con.VK_DOWN,
    "LEFT": win32con.VK_LEFT,
    "RIGHT": win32con.VK_RIGHT,
    "A": ord('X'),
    "B": ord('Z'),
    "L": ord('A'),
    "R": ord('S'),
    "START": win32con.VK_RETURN,
    "SELECT": win32con.VK_BACK,
    # Shortcuts
    "F1": win32con.VK_F1,
    "SHIFT": win32con.VK_SHIFT
}

import win32process

def get_hwnds_for_pid(pid):
    def callback(hwnd, hwnds):
        try:
            _, found_pid = win32process.GetWindowThreadProcessId(hwnd)
            if found_pid == pid:
                title = win32gui.GetWindowText(hwnd)
                # mGBA windows typically have "mGBA" or the ROM name in the title
                if "mGBA" in title or "Quetzal" in title:
                    hwnds.append(hwnd)
        except:
            pass
        return True
    
    hwnds = []
    win32gui.EnumWindows(callback, hwnds)
    return hwnds

def main():
    if len(sys.argv) < 3:
        print("Usage: python input_proxy.py <pid> <count>")
        return

    pid = int(sys.argv[1])
    expected_count = int(sys.argv[2])
    
    print(f"[InputProxy] Searching for {expected_count} windows for PID {pid}...")
    
    hwnds = []
    retries = 20
    while len(hwnds) < expected_count and retries > 0:
        hwnds = get_hwnds_for_pid(pid)
        if len(hwnds) < expected_count:
            time.sleep(1)
            retries -= 1
            
    if not hwnds:
        print("[InputProxy] Error: No windows found!")
        return
    
    # Sort hwnds by title or something stable if possible
    # mGBA windows are usually ordered by slot in the Enum order or title
    hwnds.sort(key=lambda x: win32gui.GetWindowText(x))
    
    print(f"[InputProxy] Found {len(hwnds)} windows. Ready for input.")
    sys.stdout.flush()

    while True:
        line = sys.stdin.readline()
        if not line:
            break
        
        try:
            parts = line.strip().split(',')
            if len(parts) != 3:
                continue
            
            slot = int(parts[0]) - 1 # 0-indexed for list
            key_name = parts[1].upper()
            state = int(parts[2]) # 1 for pressed, 0 for released
            
            if slot < 0 or slot >= len(hwnds):
                continue
                
            hwnd = hwnds[slot]
            vk = KEY_MAP.get(key_name)
            
            if vk:
                msg = win32con.WM_KEYDOWN if state == 1 else win32con.WM_KEYUP
                win32api.PostMessage(hwnd, msg, vk, 0)
                
        except Exception as e:
            print(f"[InputProxy] Error: {e}")
            sys.stdout.flush()

if __name__ == "__main__":
    main()
