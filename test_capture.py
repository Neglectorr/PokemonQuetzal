import sys
import time
import win32gui
import win32ui
import win32process
import numpy as np
import cv2

import ctypes

def get_hwnds_for_pid(pid):
    def callback(hwnd, hwnds):
        _, found_pid = win32process.GetWindowThreadProcessId(hwnd)
        if found_pid == pid:
            hwnds.append(hwnd)
        return True
    hwnds = []
    win32gui.EnumWindows(callback, hwnds)
    return hwnds

def capture_window(hwnd):
    left, top, right, bottom = win32gui.GetWindowRect(hwnd)
    width = right - left
    height = bottom - top
    if width <= 0 or height <= 0: return None

    client_left, client_top, client_right, client_bottom = win32gui.GetClientRect(hwnd)
    client_width = client_right - client_left
    client_height = client_bottom - client_top

    hwndDC = win32gui.GetWindowDC(hwnd)
    mfcDC = win32ui.CreateDCFromHandle(hwndDC)
    saveDC = mfcDC.CreateCompatibleDC()
    
    saveBitMap = win32ui.CreateBitmap()
    saveBitMap.CreateCompatibleBitmap(mfcDC, width, height)
    saveDC.SelectObject(saveBitMap)
    
    try:
        result = ctypes.windll.user32.PrintWindow(hwnd, saveDC.GetSafeHdc(), 3)
    except:
        result = ctypes.windll.user32.PrintWindow(hwnd, saveDC.GetSafeHdc(), 1)
        
    bmpinfo = saveBitMap.GetInfo()
    bmpstr = saveBitMap.GetBitmapBits(True)
    
    img = np.frombuffer(bmpstr, dtype='uint8')
    img.shape = (bmpinfo['bmHeight'], bmpinfo['bmWidth'], 4)
    
    win32gui.DeleteObject(saveBitMap.GetHandle())
    saveDC.DeleteDC()
    mfcDC.DeleteDC()
    win32gui.ReleaseDC(hwnd, hwndDC)

    if result != 1: return None
        
    border_left = (width - client_width) // 2
    border_top = (height - client_height) - border_left
    img = img[border_top:border_top+client_height, border_left:border_left+client_width]
    img = cv2.resize(img, (240, 160), interpolation=cv2.INTER_AREA)
    img = cv2.cvtColor(img, cv2.COLOR_BGRA2BGR)
    return img

if __name__ == '__main__':
    pid = int(sys.argv[1])
    hwnd = None
    for _ in range(50):
        for h in get_hwnds_for_pid(pid):
            title = win32gui.GetWindowText(h)
            if "- mGBA" in title or "mGBA" in title:
                hwnd = h
                break
        if hwnd: break
        time.sleep(0.1)
    
    if not hwnd:
        print("Could not find window")
        sys.exit(1)
        
    print(f"Captured window: {hwnd}, title: {win32gui.GetWindowText(hwnd)}")
    time.sleep(2) # let game render a few frames
    img = capture_window(hwnd)
    if img is not None:
        cv2.imwrite("test_capture.png", img)
        avg_color = np.average(img)
        print("Captured! Average color value:", avg_color)
    else:
        print("PrintWindow failed")
