
import win32gui
import win32con
import win32api
import time
import sys

def test_hardcoded_alt_f(pid):
    hwnds = []
    def cb(h, _):
        import win32process
        _, p = win32process.GetWindowThreadProcessId(h)
        if p == pid: hwnds.append(h)
        return True
    win32gui.EnumWindows(cb, None)
    if not hwnds: return
    hwnd = hwnds[0]

    print(f"Sending hardcoded Alt+F to HWND {hwnd}...")
    # WM_SYSKEYDOWN for Menu (Alt)
    win32api.PostMessage(hwnd, win32con.WM_SYSKEYDOWN, win32con.VK_MENU, 0x20380001)
    time.sleep(0.1)
    # WM_SYSKEYDOWN for 'F' with Alt bit set
    win32api.PostMessage(hwnd, win32con.WM_SYSKEYDOWN, ord('F'), 0x20210001)
    time.sleep(0.1)
    # WM_SYSKEYUP for 'F'
    win32api.PostMessage(hwnd, win32con.WM_SYSKEYUP, ord('F'), 0xE0210001)
    time.sleep(0.1)
    # WM_SYSKEYUP for Menu (Alt)
    win32api.PostMessage(hwnd, win32con.WM_SYSKEYUP, win32con.VK_MENU, 0xC0380001)
    
    print("Sequence sent. Waiting 2s for menu...")
    time.sleep(2.0)
    
    # Send Enter just in case it opened and we want to see if it triggers 'Open ROM' (which is first)
    print("Tapping Enter...")
    win32api.PostMessage(hwnd, win32con.WM_KEYDOWN, win32con.VK_RETURN, 0x001C0001)
    time.sleep(0.1)
    win32api.PostMessage(hwnd, win32con.WM_KEYUP, win32con.VK_RETURN, 0xC01C0001)

if __name__ == "__main__":
    test_hardcoded_alt_f(int(sys.argv[1]))
