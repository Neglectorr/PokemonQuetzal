
import win32api
import win32con
import win32gui
import win32process
import time
import subprocess
import sys

def get_hwnds_for_pid(pid):
    hwnds = []
    def cb(h, _):
        _, p = win32process.GetWindowThreadProcessId(h)
        if p == pid and win32gui.GetClientRect(h)[2] > 100:
            hwnds.append(h)
        return True
    win32gui.EnumWindows(cb, None)
    return hwnds

def k(hwnd, vk):
    print(f"Sending VK {vk} to {hwnd}")
    win32api.PostMessage(hwnd, win32con.WM_KEYDOWN, vk, 0)
    time.sleep(0.05)
    win32api.PostMessage(hwnd, win32con.WM_KEYUP, vk, 0)
    time.sleep(0.4)

def main():
    ini_path = r"c:\PassionProjects\GBAEmu\PokemonQuetzal\mgba_native\mGBA-0.10.3-win64\qt.ini"
    rom_path = r"C:/PassionProjects/GBAEmu/PokemonQuetzal/roms/QuetzalEnglishAlpha8v4.gba"
    
    print("STEP 1: Starting mGBA...")
    mgba_exe = r"c:\PassionProjects\GBAEmu\PokemonQuetzal\mgba_native\mGBA-0.10.3-win64\mGBA.exe"
    proc = subprocess.Popen([mgba_exe])
    time.sleep(4)
    pid = proc.pid
    
    hwnd = get_hwnds_for_pid(pid)[0]
    print(f"Target HWND: {hwnd}")

    print("\nSTEP 2: Navigating Recent menu blindly...")
    # Clear any state
    win32api.PostMessage(hwnd, win32con.WM_KEYDOWN, win32con.VK_ESCAPE, 0)
    time.sleep(0.1)
    win32api.PostMessage(hwnd, win32con.WM_KEYUP, win32con.VK_ESCAPE, 0)
    time.sleep(1)

    # Alt+F
    print("Sending Alt+F")
    win32api.PostMessage(hwnd, win32con.WM_SYSKEYDOWN, ord('F'), 1 << 29)
    time.sleep(0.1)
    win32api.PostMessage(hwnd, win32con.WM_SYSKEYUP, ord('F'), 1 << 29)
    time.sleep(1.0)

    # Press Down 8 times to get to 'Recent'
    for _ in range(8):
        k(hwnd, win32con.VK_DOWN)
    
    # Press Right to open submenu
    k(hwnd, win32con.VK_RIGHT)
    
    # Press Enter to select 0th item
    k(hwnd, win32con.VK_RETURN)
    
    print("Waiting 5s for ROM load...")
    time.sleep(5)
    
    final_title = win32gui.GetWindowText(hwnd)
    print(f"Final Title: '{final_title}'")
    
    if "Quetzal" in final_title:
        print("\n🏆 SUCCESS! ROM loaded blindly via Recent menu navigation.")
    else:
        print("\n❌ FAILED. Title did not change.")

    proc.terminate()

if __name__ == "__main__":
    main()
