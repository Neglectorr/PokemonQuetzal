import sys
import ctypes
import win32gui
import win32ui
import win32process
import numpy as np
import cv2
import time

def get_hwnds_for_pid(pid):
    def callback(hwnd, hwnds):
        _, found_pid = win32process.GetWindowThreadProcessId(hwnd)
        if found_pid == pid:
            hwnds.append(hwnd)
        return True
    hwnds = []
    win32gui.EnumWindows(callback, hwnds)
    return hwnds

def run_test(pid):
    hwnd = None
    for h in get_hwnds_for_pid(pid):
        title = win32gui.GetWindowText(h)
        if "- mGBA" in title or "mGBA" in title:
            hwnd = h
            break

    if not hwnd:
        print("No window found")
        return

    left, top, right, bottom = win32gui.GetWindowRect(hwnd)
    width = right - left
    height = bottom - top

    client_left, client_top, client_right, client_bottom = win32gui.GetClientRect(hwnd)
    client_width = client_right - client_left
    client_height = client_bottom - client_top

    hwndDC = win32gui.GetWindowDC(hwnd)
    mfcDC = win32ui.CreateDCFromHandle(hwndDC)
    saveDC = mfcDC.CreateCompatibleDC()
    
    saveBitMap = win32ui.CreateBitmap()
    
    # Try capturing onto a bitmap exactly the size of the client area
    saveBitMap.CreateCompatibleBitmap(mfcDC, client_width, client_height)
    saveDC.SelectObject(saveBitMap)
    
    # 3 = PW_CLIENTONLY | PW_RENDERFULLCONTENT
    result = ctypes.windll.user32.PrintWindow(hwnd, saveDC.GetSafeHdc(), 3)
    
    bmpstr = saveBitMap.GetBitmapBits(True)
    img = np.frombuffer(bmpstr, dtype='uint8')
    img.shape = (client_height, client_width, 4)
    
    win32gui.DeleteObject(saveBitMap.GetHandle())
    saveDC.DeleteDC()
    mfcDC.DeleteDC()
    win32gui.ReleaseDC(hwnd, hwndDC)

    img = cv2.cvtColor(img, cv2.COLOR_BGRA2BGR)
    cv2.imwrite("test_clientonly.png", img)
    print(f"Captured {client_width}x{client_height}! Average color: {np.mean(img)}")

if __name__ == "__main__":
    run_test(int(sys.argv[1]))
