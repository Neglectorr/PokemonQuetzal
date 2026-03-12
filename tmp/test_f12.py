
import win32gui
import win32con
import win32api
import win32process
import time
import sys

def test_f12(pid):
    hwnds = []
    def cb(h, _):
        _, p = win32process.GetWindowThreadProcessId(h)
        if p == pid: hwnds.append(h)
        return True
    win32gui.EnumWindows(cb, None)
    if not hwnds: 
        print("mGBA not found")
        return
    hwnd = hwnds[0]

    print(f"Sending F12 blindly to HWND {hwnd} (mapped to New Multiplayer Window)...")
    
    # 1. Tap F12
    win32api.PostMessage(hwnd, win32con.WM_KEYDOWN, win32con.VK_F12, 0)
    time.sleep(0.05)
    win32api.PostMessage(hwnd, win32con.WM_KEYUP, win32con.VK_F12, 0)
    
    time.sleep(3.0)
    
    hwnds_post = []
    win32gui.EnumWindows(cb, None)
    print(f"Window count: {len(hwnds_post)} (Original: {len(hwnds)})")
    if len(hwnds_post) > len(hwnds):
        print("SUCCESS! Window spawned via F12.")
    else:
        # Try with lParam (scan code for F12 is 0x58)
        print("Trying with specific lParam...")
        lParam = 0x0001 | (0x58 << 16)
        win32api.PostMessage(hwnd, win32con.WM_KEYDOWN, win32con.VK_F12, lParam)
        time.sleep(0.1)
        win32api.PostMessage(hwnd, win32con.WM_KEYUP, win32con.VK_F12, lParam | 0xC0000000)
        time.sleep(3.0)
        
        hwnds_final = []
        win32gui.EnumWindows(cb, None)
        if len(hwnds_final) > len(hwnds):
            print("SUCCESS! Window spawned via F12 (with lParam).")
        else:
            print("FAILED. F12 did not trigger window spawn.")

if __name__ == "__main__":
    test_f12(int(sys.argv[1]))
