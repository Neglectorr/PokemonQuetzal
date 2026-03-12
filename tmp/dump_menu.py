
import win32gui
import win32con
import win32api
import win32process
from pywinauto.application import Application
import time
import sys

def dump_menu(hwnd):
    hMenu = win32gui.GetMenu(hwnd)
    if not hMenu:
        print("No menu found for this window.")
        return
    
    count = win32gui.GetMenuItemCount(hMenu)
    for i in range(count):
        text = win32gui.GetMenuString(hMenu, i, win32con.MF_BYPOSITION)
        print(f"Top-level Menu {i}: {text}")
        hSubMenu = win32gui.GetSubMenu(hMenu, i)
        if hSubMenu:
            subCount = win32gui.GetMenuItemCount(hSubMenu)
            for j in range(subCount):
                subText = win32gui.GetMenuString(hSubMenu, j, win32con.MF_BYPOSITION)
                subId = win32gui.GetMenuItemID(hSubMenu, j)
                print(f"  Sub {j}: {subText} (ID: {subId})")
                
                # Check for "Recent" submenu
                if "recent" in subText.lower():
                    hRecent = win32gui.GetSubMenu(hSubMenu, j)
                    if hRecent:
                        recentCount = win32gui.GetMenuItemCount(hRecent)
                        for k in range(recentCount):
                            recentText = win32gui.GetMenuString(hRecent, k, win32con.MF_BYPOSITION)
                            recentId = win32gui.GetMenuItemID(hRecent, k)
                            print(f"    Recent {k}: {recentText} (ID: {recentId})")

def main():
    if len(sys.argv) < 2:
        print("Usage: python dump_menu.py <pid>")
        return
    pid = int(sys.argv[1])
    
    def cb(h, _):
        _, p = win32process.GetWindowThreadProcessId(h)
        if p == pid and win32gui.GetClientRect(h)[2] > 100:
            print(f"\nDumping menu for HWND {h}:")
            dump_menu(h)
        return True
    win32gui.EnumWindows(cb, None)

if __name__ == "__main__":
    main()
