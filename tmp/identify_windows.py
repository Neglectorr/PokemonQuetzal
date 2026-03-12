import win32gui
import win32process
import psutil

def get_window_info():
    def callback(hwnd, windows):
        if win32gui.IsWindowVisible(hwnd):
            title = win32gui.GetWindowText(hwnd)
            class_name = win32gui.GetClassName(hwnd)
            _, pid = win32process.GetWindowThreadProcessId(hwnd)
            try:
                process = psutil.Process(pid)
                proc_name = process.name()
            except:
                proc_name = "unknown"
            
            if title or class_name:
                windows.append({
                    "hwnd": hwnd,
                    "title": title,
                    "class": class_name,
                    "pid": pid,
                    "process": proc_name
                })
        return True

    windows = []
    win32gui.EnumWindows(callback, windows)
    return windows

if __name__ == "__main__":
    for w in get_window_info():
        if "mgba" in w["process"].lower() or "mgba" in w["title"].lower():
            print(f"HWND: {w['hwnd']} | PID: {w['pid']} | Process: {w['process']} | Class: {w['class']} | Title: {w['title']}")
