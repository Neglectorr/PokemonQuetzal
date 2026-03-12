
from pywinauto.application import Application
import sys
import time
import win32gui
import win32process

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
    print("STEP 1: Starting mGBA...")
    mgba_exe = r"c:\PassionProjects\GBAEmu\PokemonQuetzal\mgba_native\mGBA-0.10.3-win64\mGBA.exe"
    import subprocess
    proc = subprocess.Popen([mgba_exe])
    time.sleep(4)
    pid = proc.pid
    
    # Pre-patch qt.ini to ensure something is in Recent
    ini_path = r"c:\PassionProjects\GBAEmu\PokemonQuetzal\mgba_native\mGBA-0.10.3-win64\qt.ini"
    rom_path = r"C:/PassionProjects/GBAEmu/PokemonQuetzal/roms/QuetzalEnglishAlpha8v4.gba"
    with open(ini_path, "r") as f: lines = f.readlines()
    with open(ini_path, "w") as f:
        for line in lines:
            if line.startswith("0="): f.write(f"0={rom_path}\n")
            else: f.write(line)

    print("STEP 2: Connecting with Win32 backend...")
    app = Application(backend="win32").connect(process=pid)
    hwnd = get_hwnds_for_pid(pid)[0]
    win = app.window(handle=hwnd)
    
    print("Directly attempting Menu Select (Win32)...")
    try:
        # Standard Win32 menu selection
        # Based on screenshot: File -> Recent -> [first item]
        # We might need to use indices if names are dynamic
        win.menu_select("File->Recent->0") 
        print("Sent menu_select command.")
    except Exception as e:
        print(f"menu_select failed: {e}")
        print("Trying by index...")
        try:
            # File is usually 0, Recent is usually near bottom
            # Based on screenshot, Recent is 9th (index 8)
            win.menu_select("#0 -> #8 -> #0")
            print("Sent menu_select by index.")
        except Exception as e2:
            print(f"menu_select by index failed: {e2}")

    print("Waiting 5s for ROM load...")
    time.sleep(5)
    
    final_title = win32gui.GetWindowText(hwnd)
    print(f"Final Title: '{final_title}'")
    
    if "Quetzal" in final_title:
        print("\n🏆 SUCCESS! ROM loaded blindly via Win32 Menu Select.")
    else:
        print("\n❌ FAILED. Title did not change.")

    proc.terminate()

if __name__ == "__main__":
    main()
