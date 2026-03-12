
import win32gui
import win32con
import win32process
import win32api
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

def blind_key(hwnd, vk, is_down=True):
    scan_code = win32api.MapVirtualKey(vk, 0)
    lParam = 0x0001 | (scan_code << 16)
    if not is_down:
        lParam |= (1 << 30) | (1 << 31)
        msg = win32con.WM_KEYUP
    else:
        msg = win32con.WM_KEYDOWN
    win32api.PostMessage(hwnd, msg, vk, lParam)

def test_arrows(pid):
    hwnds = get_hwnds_for_pid(pid)
    if not hwnds:
        print("mGBA not found")
        return
    hwnd = hwnds[0]
    
    for i in range(1, 15):
        print(f"Testing {i} 'Down' taps...")
        pre_count = len(get_hwnds_for_pid(pid))
        
        # 1. Alt Down
        blind_key(hwnd, win32con.VK_MENU, True)
        time.sleep(0.1)
        # 2. Tap F
        blind_key(hwnd, ord('F'), True)
        time.sleep(0.05)
        blind_key(hwnd, ord('F'), False)
        time.sleep(0.5)
        
        # 3. Tap Down 'i' times
        for _ in range(i):
            blind_key(hwnd, win32con.VK_DOWN, True)
            time.sleep(0.05)
            blind_key(hwnd, win32con.VK_DOWN, False)
            time.sleep(0.1)
            
        # 4. Tap Enter
        blind_key(hwnd, win32con.VK_RETURN, True)
        time.sleep(0.05)
        blind_key(hwnd, win32con.VK_RETURN, False)
        time.sleep(0.5)
        
        # 5. Alt Up
        blind_key(hwnd, win32con.VK_MENU, False)
        time.sleep(2.0)
        
        post_count = len(get_hwnds_for_pid(pid))
        if post_count > pre_count:
            print(f"SUCCESS! {i} 'Down' taps spawned a window.")
            return i
            
        # Clear menus if failed
        blind_key(hwnd, win32con.VK_ESCAPE, True)
        time.sleep(0.05)
        blind_key(hwnd, win32con.VK_ESCAPE, False)
        time.sleep(0.5)

if __name__ == "__main__":
    test_arrows(int(sys.argv[1]))
