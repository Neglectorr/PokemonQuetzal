import win32gui
import win32ui
import ctypes
import numpy as np
import cv2
import os

def capture_window(hwnd):
    client_left, client_top, client_right, client_bottom = win32gui.GetClientRect(hwnd)
    client_width = client_right - client_left
    client_height = client_bottom - client_top
    if client_width <= 0 or client_height <= 0:
        return None

    hwndDC = win32gui.GetWindowDC(hwnd)
    mfcDC = win32ui.CreateDCFromHandle(hwndDC)
    saveDC = mfcDC.CreateCompatibleDC()
    saveBitMap = win32ui.CreateBitmap()
    saveBitMap.CreateCompatibleBitmap(mfcDC, client_width, client_height)
    saveDC.SelectObject(saveBitMap)
    
    try:
        result = ctypes.windll.user32.PrintWindow(hwnd, saveDC.GetSafeHdc(), 2)
    except:
        result = ctypes.windll.user32.PrintWindow(hwnd, saveDC.GetSafeHdc(), 0)
        
    bmpstr = saveBitMap.GetBitmapBits(True)
    img = np.frombuffer(bmpstr, dtype='uint8')
    img.shape = (client_height, client_width, 4)
    
    win32gui.DeleteObject(saveBitMap.GetHandle())
    saveDC.DeleteDC()
    mfcDC.DeleteDC()
    win32gui.ReleaseDC(hwnd, hwndDC)

    return cv2.cvtColor(img, cv2.COLOR_BGRA2BGR)

def find_errors(hwnd, results):
    title = win32gui.GetWindowText(hwnd)
    if "An error occurred" in title:
        results.append(hwnd)
    return True

errors = []
win32gui.EnumWindows(find_errors, errors)

for i, hwnd in enumerate(errors):
    img = capture_window(hwnd)
    if img is not None:
        path = f"C:/PassionProjects/GBAEmu/PokemonQuetzal/tmp/error_{i}.png"
        cv2.imwrite(path, img)
        print(f"Captured error window {hwnd} to {path}")
