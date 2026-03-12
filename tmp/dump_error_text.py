import win32gui
import win32con
import ctypes

def get_text(hwnd):
    length = win32gui.SendMessage(hwnd, win32con.WM_GETTEXTLENGTH, 0, 0)
    buffer = ctypes.create_unicode_buffer(length + 1)
    win32gui.SendMessage(hwnd, win32con.WM_GETTEXT, length + 1, buffer)
    return buffer.value

def callback(hwnd, results):
    title = win32gui.GetWindowText(hwnd)
    if "An error occurred" in title or "mgba" in title.lower():
        texts = []
        def child_callback(child_hwnd, _):
            txt = get_text(child_hwnd)
            if txt:
                texts.append(txt)
            return True
        win32gui.EnumChildWindows(hwnd, child_callback, None)
        results.append((hwnd, title, texts))
    return True

results = []
win32gui.EnumWindows(callback, results)

for hwnd, title, texts in results:
    print(f"Window HWND: {hwnd}")
    print(f"  Title: {title}")
    print(f"  Content: {texts}")
    print("-" * 20)
