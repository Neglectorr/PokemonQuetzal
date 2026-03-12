
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
        if p == pid:
            rect = win32gui.GetClientRect(h)
            if rect[2]-rect[0] > 100: hwnds.append(h)
        return True
    win32gui.EnumWindows(cb, None)
    return hwnds

def blind_key_combo(hwnd, modifier_vk, key_vk):
    # Map virtual keys
    mod_scan = win32api.MapVirtualKey(modifier_vk, 0)
    key_scan = win32api.MapVirtualKey(key_vk, 0)
    
    # Generic lParam bits
    # 0-15: repeat (1)
    # 16-23: scan
    # 24: extended (0)
    # 29: context (0)
    # 30: previous bit
    # 31: transition bit
    
    # Modifier Down
    win32api.PostMessage(hwnd, win32con.WM_KEYDOWN, modifier_vk, 0x0001 | (mod_scan << 16))
    time.sleep(0.05)
    
    # Key Down
    win32api.PostMessage(hwnd, win32con.WM_KEYDOWN, key_vk, 0x0001 | (key_scan << 16))
    time.sleep(0.1)
    
    # Key Up
    win32api.PostMessage(hwnd, win32con.WM_KEYUP, key_vk, 0xC001 | (key_scan << 16))
    time.sleep(0.05)
    
    # Modifier Up
    win32api.PostMessage(hwnd, win32con.WM_KEYUP, modifier_vk, 0xC001 | (mod_scan << 16))

def main():
    ini_path = r"c:\PassionProjects\GBAEmu\PokemonQuetzal\mgba_native\mGBA-0.10.3-win64\qt.ini"
    rom_path = r"C:/PassionProjects/GBAEmu/PokemonQuetzal/roms/QuetzalEnglishAlpha8v4.gba"
    
    print("STEP 1: Patching qt.ini [mru] with targeting ROM...")
    with open(ini_path, "r") as f:
        lines = f.readlines()
    
    new_lines = []
    in_mru = False
    found_0 = False
    for line in lines:
        if "[mru]" in line:
            in_mru = True
        elif line.startswith("[") and in_mru:
            in_mru = False
        
        if in_mru and line.startswith("0="):
            new_lines.append(f"0={rom_path}\n")
            found_0 = True
        else:
            new_lines.append(line)
    
    # If not found, we should probably insert it or fail
    if not found_0 and in_mru:
        # Insert at the top of mru
        idx = next(i for i, l in enumerate(new_lines) if "[mru]" in l)
        new_lines.insert(idx + 1, f"0={rom_path}\n")
    
    with open(ini_path, "w") as f:
        f.writelines(new_lines)

    print("STEP 2: Starting mGBA...")
    mgba_exe = r"c:\PassionProjects\GBAEmu\PokemonQuetzal\mgba_native\mGBA-0.10.3-win64\mGBA.exe"
    proc = subprocess.Popen([mgba_exe])
    time.sleep(4)
    pid = proc.pid
    
    hwnds = get_hwnds_for_pid(pid)
    if not hwnds:
        print("FAILED: No mGBA window found.")
        proc.terminate()
        return
    
    hwnd = hwnds[0]
    print(f"Target HWND: {hwnd}, Initial Title: '{win32gui.GetWindowText(hwnd)}'")

    print("\nSTEP 3: Sending Ctrl+0 blindly...")
    # 0x30 is key '0'
    blind_key_combo(hwnd, win32con.VK_CONTROL, 0x30)
    
    # Wait for title change
    print("Waiting 5s for ROM load...")
    time.sleep(5)
    
    final_title = win32gui.GetWindowText(hwnd)
    print(f"Final Title: '{final_title}'")
    
    if "Quetzal" in final_title:
        print("\n🏆 SUCCESS! ROM loaded blindly via Ctrl+0.")
    else:
        print("\n❌ FAILED. Title did not change as expected.")

    proc.terminate()

if __name__ == "__main__":
    main()
