import win32gui
import win32con
import ctypes

def get_text(hwnd):
    length = win32gui.SendMessage(hwnd, win32con.WM_GETTEXTLENGTH, 0, 0)
    if length <= 0: return ""
    buffer = ctypes.create_unicode_buffer(length + 1)
    win32gui.SendMessage(hwnd, win32con.WM_GETTEXT, length + 1, buffer)
    return buffer.value

def callback(hwnd, results):
    title = win32gui.GetWindowText(hwnd)
    if "An error occurred" in title:
        texts = []
        def child_callback(child_hwnd, _):
            txt = get_text(child_hwnd)
            if txt and len(txt) > 2:
                texts.append(txt)
            return True
        win32gui.EnumChildWindows(hwnd, child_callback, None)
        results.append((hwnd, title, texts))
    return True

results = []
win32gui.EnumWindows(callback, results)

if not results:
    print("No error windows found.")
else:
    for hwnd, title, texts in results:
        print(f"ERROR WINDOW {hwnd}: {texts}")
