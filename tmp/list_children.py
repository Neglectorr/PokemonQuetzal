import win32gui
import sys

def list_children(parent_hwnd):
    children = []
    def callback(hwnd, extra):
        children.append(hwnd)
        return True
    win32gui.EnumChildWindows(parent_hwnd, callback, None)
    return children

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python list_children.py <hwnd>")
        sys.exit(1)
    
    parent = int(sys.argv[1])
    print(f"Parent: {parent} ({win32gui.GetWindowText(parent)})")
    
    children = list_children(parent)
    for c in children:
        print(f"  Child HWND: {c}, Class: {win32gui.GetClassName(c)}, Title: '{win32gui.GetWindowText(c)}'")
