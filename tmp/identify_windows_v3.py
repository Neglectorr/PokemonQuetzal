import win32gui
import win32process
import psutil
import json

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
    windows = get_window_info()
    with open("C:/PassionProjects/GBAEmu/PokemonQuetzal/tmp/windows.json", "w", encoding="utf-8") as f:
        json.dump(windows, f, indent=2)
