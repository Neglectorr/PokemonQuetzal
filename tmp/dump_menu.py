
import win32gui
import win32con
import sys

def dump_menu(hwnd, menu, depth=0):
    if not menu:
        return
    count = win32gui.GetMenuItemCount(menu)
    for i in range(count):
        mid = win32gui.GetMenuItemID(menu, i)
        text = win32gui.GetMenuString(menu, i, win32gui.MF_BYPOSITION)
        print("  " * depth + f"ID: {mid}, Text: {text}")
        if mid == -1: # Submenu
            submenu = win32gui.GetSubMenu(menu, i)
            dump_menu(hwnd, submenu, depth + 1)

def main():
    if len(sys.argv) < 2:
        print("Usage: python dump_menu.py <HWND>")
        return
    hwnd = int(sys.argv[1])
    menu = win32gui.GetMenu(hwnd)
    if not menu:
        print(f"No menu found for HWND {hwnd}")
        return
    dump_menu(hwnd, menu)

if __name__ == "__main__":
    main()
