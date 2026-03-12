
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

def send_ctrl_key(hwnd, vk):
    # Simulate Ctrl+Key
    # We send WM_KEYDOWN for CTRL, then WM_KEYDOWN for Key, then WM_KEYUP for Key, then WM_KEYUP for CTRL
    
    # 0x30 is '0'
    # Modifier Down
    win32api.PostMessage(hwnd, win32con.WM_KEYDOWN, win32con.VK_CONTROL, 0x00140001)
    time.sleep(0.05)
    
    # Key Down (with bit 29=0, bit 30=0, bit 31=0)
    # For some reason, Qt might want bit 29 (Alt) to be 0
    lParam = 0x00000001 | (win32api.MapVirtualKey(vk, 0) << 16)
    win32api.PostMessage(hwnd, win32con.WM_KEYDOWN, vk, lParam)
    time.sleep(0.1)
    
    # Key Up
    lParam |= 0xC0000000
    win32api.PostMessage(hwnd, win32con.WM_KEYUP, vk, lParam)
    time.sleep(0.05)
    
    # Modifier Up
    win32api.PostMessage(hwnd, win32con.WM_KEYUP, win32con.VK_CONTROL, 0xC0140001)

def main():
    ini_path = r"c:\PassionProjects\GBAEmu\PokemonQuetzal\mgba_native\mGBA-0.10.3-win64\qt.ini"
    rom_path = r"C:/PassionProjects/GBAEmu/PokemonQuetzal/roms/QuetzalEnglishAlpha8v4.gba"
    
    print("STEP 1: Patching qt.ini [mru] with targeting ROM...")
    with open(ini_path, "r") as f: lines = f.readlines()
    with open(ini_path, "w") as f:
        for line in lines:
            if line.startswith("0="): f.write(f"0={rom_path}\n")
            else: f.write(line)

    print("STEP 2: Starting mGBA...")
    mgba_exe = r"c:\PassionProjects\GBAEmu\PokemonQuetzal\mgba_native\mGBA-0.10.3-win64\mGBA.exe"
    proc = subprocess.Popen([mgba_exe])
    time.sleep(4)
    pid = proc.pid
    
    hwnd = get_hwnds_for_pid(pid)[0]
    print(f"Target HWND: {hwnd}, Title: '{win32gui.GetWindowText(hwnd)}'")

    print("\nSTEP 3: Sending Ctrl+0 with robust modifier simulation...")
    send_ctrl_key(hwnd, 0x30)
    
    print("Waiting 5s for ROM load...")
    time.sleep(5)
    
    final_title = win32gui.GetWindowText(hwnd)
    print(f"Final Title: '{final_title}'")
    
    if "Quetzal" in final_title:
        print("\n🏆 SUCCESS! ROM loaded blindly via Ctrl+0.")
    else:
        print("\n❌ FAILED. Ctrl+0 did not trigger load.")

    proc.terminate()

if __name__ == "__main__":
    main()
