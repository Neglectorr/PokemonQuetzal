
import win32gui
import win32con
import win32api
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

def inventory_children(hwnd):
    results = []
    def cb(h, _):
        results.append({
            "hwnd": h,
            "class": win32gui.GetClassName(h),
            "title": win32gui.GetWindowText(h),
            "rect": win32gui.GetWindowRect(h)
        })
        return True
    win32gui.EnumChildWindows(hwnd, cb, None)
    return results

def main():
    print("STEP 1: Starting mGBA...")
    mgba_exe = r"c:\PassionProjects\GBAEmu\PokemonQuetzal\mgba_native\mGBA-0.10.3-win64\mGBA.exe"
    proc = subprocess.Popen([mgba_exe])
    time.sleep(4)
    pid = proc.pid
    
    hwnd = get_hwnds_for_pid(pid)[0]
    
    print("\nSTEP 2: Triggering F11 (Select ROM)...")
    win32api.PostMessage(hwnd, win32con.WM_KEYDOWN, win32con.VK_F11, 0)
    time.sleep(0.05)
    win32api.PostMessage(hwnd, win32con.WM_KEYUP, win32con.VK_F11, 0)
    
    print("Waiting for dialog...")
    dialog_hwnd = None
    for _ in range(10):
        def cb(h, _):
            nonlocal dialog_hwnd
            title = win32gui.GetWindowText(h)
            if "Select ROM" in title:
                _, p = win32process.GetWindowThreadProcessId(h)
                if p == pid:
                    dialog_hwnd = h
            return True
        win32gui.EnumWindows(cb, None)
        if dialog_hwnd: break
        time.sleep(0.5)
    
    if not dialog_hwnd:
        print("FAILED: Dialog not found.")
        proc.terminate()
        return
    
    print(f"Dialog Found: {dialog_hwnd}. Inventorying children...")
    children = inventory_children(dialog_hwnd)
    for c in children:
        print(f"Child: HWND={c['hwnd']}, Class='{c['class']}', Title='{c['title']}', Rect={c['rect']}")

    # Try to find the edit box specifically
    edit_box = next((c for c in children if c['class'] == 'Edit'), None)
    if edit_box:
        print(f"\nFOUND EDIT BOX: {edit_box['hwnd']}")
        # Try to set text blindly
        rom_path = r"C:\PassionProjects\GBAEmu\PokemonQuetzal\roms\QuetzalEnglishAlpha8v4.gba"
        win32gui.SendMessage(edit_box['hwnd'], win32con.WM_SETTEXT, 0, rom_path)
        print("Sent WM_SETTEXT")
        time.sleep(0.5)
        # Send Enter to the dialog
        win32api.PostMessage(dialog_hwnd, win32con.WM_KEYDOWN, win32con.VK_RETURN, 0)
        print("Sent RETURN to dialog")
    
    time.sleep(3)
    print(f"Final main window title: '{win32gui.GetWindowText(hwnd)}'")
    
    proc.terminate()

if __name__ == "__main__":
    main()
