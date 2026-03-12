
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
    
    print("STEP 1: Patching qt.ini with custom shortcut and MRU...")
    with open(ini_path, "r") as f:
        content = f.read()
    
    # 1. Ensure recent0=F10 in [shortcutKey]
    if "[shortcutKey]" not in content:
        content += "\n[shortcutKey]\nrecent0=F10\n"
    else:
        # Check if recent0 already exists
        import re
        if not re.search(r"recent0=", content):
            content = content.replace("[shortcutKey]", "[shortcutKey]\nrecent0=F10")
        else:
            content = re.sub(r"recent0=.*", "recent0=F10", content)

    # 2. Ensure ROM is at 0= in [mru]
    if "[mru]" not in content:
        content += f"\n[mru]\n0={rom_path}\n"
    else:
        content = re.sub(r"0=.*", f"0={rom_path}", content)

    with open(ini_path, "w") as f:
        f.write(content)

    print("STEP 2: Starting mGBA...")
    mgba_exe = r"c:\PassionProjects\GBAEmu\PokemonQuetzal\mgba_native\mGBA-0.10.3-win64\mGBA.exe"
    proc = subprocess.Popen([mgba_exe])
    time.sleep(4)
    pid = proc.pid
    
    hwnd = get_hwnds_for_pid(pid)[0]
    print(f"Target HWND: {hwnd}, Title: '{win32gui.GetWindowText(hwnd)}'")

    print("\nSTEP 3: Sending F10 blindly...")
    win32api.PostMessage(hwnd, win32con.WM_KEYDOWN, win32con.VK_F10, 0)
    time.sleep(0.05)
    win32api.PostMessage(hwnd, win32con.WM_KEYUP, win32con.VK_F10, 0)
    
    print("Waiting 5s for ROM load...")
    time.sleep(5)
    
    final_title = win32gui.GetWindowText(hwnd)
    print(f"Final Title: '{final_title}'")
    
    if "Quetzal" in final_title:
        print("\n🏆 SUCCESS! ROM loaded blindly via custom F10 shortcut.")
    else:
        print("\n❌ FAILED. recent0=F10 did not trigger load (or name is wrong).")

    proc.terminate()

if __name__ == "__main__":
    main()
