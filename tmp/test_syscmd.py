
import win32gui
import win32con
import win32process
import time
import sys

def get_hwnds_for_pid(pid):
    def callback(hwnd, hwnds):
        _, found_pid = win32process.GetWindowThreadProcessId(hwnd)
        if found_pid == pid:
            hwnds.append(hwnd)
        return True
    hwnds = []
    win32gui.EnumWindows(callback, hwnds)
    return hwnds

def test_syscommand(pid):
    hwnds = get_hwnds_for_pid(pid)
    if not hwnds:
        print("mGBA not found")
        return
    hwnd = hwnds[0]
    
    print(f"Sending WM_SYSCOMMAND SC_KEYMENU 'f' to HWND {hwnd}...")
    # This is equivalent to pressing Alt+F
    win32gui.PostMessage(hwnd, win32con.WM_SYSCOMMAND, win32con.SC_KEYMENU, ord('f'))
    
    time.sleep(2.0)
    print("If menu opened, we will now tap Down 15 times and Enter.")
    
    for _ in range(15):
        win32gui.PostMessage(hwnd, win32con.WM_KEYDOWN, win32con.VK_DOWN, 0)
        time.sleep(0.05)
        win32gui.PostMessage(hwnd, win32con.WM_KEYUP, win32con.VK_DOWN, 0)
        time.sleep(0.1)
        
    win32gui.PostMessage(hwnd, win32con.WM_KEYDOWN, win32con.VK_RETURN, 0)
    time.sleep(0.05)
    win32gui.PostMessage(hwnd, win32con.WM_KEYUP, win32con.VK_RETURN, 0)

if __name__ == "__main__":
    test_syscommand(int(sys.argv[1]))
