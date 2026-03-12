
import win32api
import win32con
import win32gui
import win32process
import time
import subprocess
import os

def get_hwnds_for_pid(pid):
    hwnds = []
    def cb(h, _):
        _, p = win32process.GetWindowThreadProcessId(h)
        if p == pid and win32gui.GetClientRect(h)[2] > 100:
            hwnds.append(h)
        return True
    win32gui.EnumWindows(cb, None)
    return hwnds

def main():
    ini_path = r"c:\PassionProjects\GBAEmu\PokemonQuetzal\mgba_native\mGBA-0.10.3-win64\qt.ini"
    rom_path = r"C:/PassionProjects/GBAEmu/PokemonQuetzal/roms/QuetzalEnglishAlpha8v4.gba"
    
    # 0. Patch INI
    with open(ini_path, "r") as f:
        lines = f.readlines()
    with open(ini_path, "w") as f:
        for line in lines:
            if line.startswith("0="): f.write(f"0={rom_path}\n")
            else: f.write(line)

    print("STEP 1: Starting mGBA...")
    mgba_exe = r"c:\PassionProjects\GBAEmu\PokemonQuetzal\mgba_native\mGBA-0.10.3-win64\mGBA.exe"
    proc = subprocess.Popen([mgba_exe])
    time.sleep(4)
    pid = proc.pid
    
    hwnds = get_hwnds_for_pid(pid)
    if not hwnds: return
    hwnd = hwnds[0]

    print(f"Brute forcing WM_COMMAND for {hwnd}...")
    # Recent items in many apps are around 40000+ or small IDs
    # Let's try 1 to 2000 first
    for cmd_id in range(1, 1000):
        if cmd_id % 100 == 0: print(f"Trying range {cmd_id}...")
        win32api.PostMessage(hwnd, win32con.WM_COMMAND, cmd_id, 0)
        time.sleep(0.01) # Very fast send
        
        # Check title occasionally
        if cmd_id % 10 == 0:
            title = win32gui.GetWindowText(hwnd)
            if "Quetzal" in title:
                print(f"!!! FOUND COMMAND ID: {cmd_id}")
                print(f"Title changed to: {title}")
                break
    
    # Try another range if not found
    if "Quetzal" not in win32gui.GetWindowText(hwnd):
         print("Not found in 1-1000. Trying 30000-32000 (often used for MRU)...")
         for cmd_id in range(30000, 32000):
            win32api.PostMessage(hwnd, win32con.WM_COMMAND, cmd_id, 0)
            time.sleep(0.005)
            if cmd_id % 10 == 0:
                if "Quetzal" in win32gui.GetWindowText(hwnd):
                    print(f"!!! FOUND COMMAND ID: {cmd_id}")
                    break

    proc.terminate()

if __name__ == "__main__":
    main()
