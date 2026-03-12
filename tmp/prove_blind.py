
import win32gui
import win32con
import win32api
import win32process
import time
import subprocess
import os
from pywinauto.application import Application

def get_hwnds_for_pid(pid):
    hwnds = []
    def cb(h, _):
        _, p = win32process.GetWindowThreadProcessId(h)
        if p == pid:
            rect = win32gui.GetClientRect(h)
            if rect[2]-rect[0] > 100: hwnds.append(h)
        return True
    win32gui.EnumWindows(cb, None)
    return hwnds

def main():
    print("STEP 1: Starting mGBA...")
    mgba_path = r"c:\PassionProjects\GBAEmu\PokemonQuetzal\mgba_native\mGBA-0.10.3-win64\mGBA.exe"
    rom_path = r"c:\PassionProjects\GBAEmu\PokemonQuetzal\roms\QuetzalEnglishAlpha8v4.gba"
    
    proc = subprocess.Popen([mgba_path])
    time.sleep(4)
    pid = proc.pid
    hwnds = get_hwnds_for_pid(pid)
    print(f"Initial mGBA windows: {len(hwnds)} (HWNDs: {hwnds})")
    
    print("\nSTEP 2: Starting Notepad and giving it focus...")
    notepad = subprocess.Popen(["notepad.exe"])
    time.sleep(2)
    fg = win32gui.GetForegroundWindow()
    print(f"Foreground Window HWND: {fg}, Title: '{win32gui.GetWindowText(fg)}'")
    
    print("\nSTEP 3: Running spawn_multiplayer.py BLINDLY...")
    # We'll run it for 2 players
    cmd = f'python server/spawn_multiplayer.py {pid} "{rom_path}" "{rom_path}"'
    spawn_proc = subprocess.Popen(cmd, shell=True)
    
    print("Waiting for spawn_multiplayer.py to complete...")
    spawn_proc.wait(timeout=120)
    
    print("\nSTEP 4: Verifying results...")
    hwnds_final = get_hwnds_for_pid(pid)
    print(f"Final mGBA windows: {len(hwnds_final)}")
    
    results = []
    for h in hwnds_final:
        title = win32gui.GetWindowText(h)
        print(f"Window {h} Title: '{title}'")
        results.append(title)

    running_games = [r for r in results if "mGBA -" in r and "0.10.3" in r and len(r) > 20]
    
    if len(hwnds_final) >= 2 and len(running_games) >= 2:
        print("\n🏆 SUCCESS! Windows spawned and ROMs loaded BLINDLY while Notepad was in the foreground.")
    else:
        print("\n❌ FAILED. Final titles don't indicate running games or window count is wrong.")

    # proc.terminate()
    # notepad.terminate()

if __name__ == "__main__":
    main()
