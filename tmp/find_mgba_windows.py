import win32gui
import win32process

def get_hwnds_for_pid(pid):
    def callback(hwnd, hwnds):
        if win32gui.IsWindowVisible(hwnd):
            _, found_pid = win32process.GetWindowThreadProcessId(hwnd)
            if found_pid == pid:
                print(f"HWND: {hwnd}, Class: {win32gui.GetClassName(hwnd)}, Title: '{win32gui.GetWindowText(hwnd)}'")
                hwnds.append(hwnd)
        return True
    hwnds = []
    win32gui.EnumWindows(callback, hwnds)
    return hwnds

if __name__ == "__main__":
    import psutil
    for proc in psutil.process_iter(['pid', 'name']):
        if 'mgba' in proc.info['name'].lower():
            print(f"Found process: {proc.info['name']} (PID: {proc.info['pid']})")
            get_hwnds_for_pid(proc.info['pid'])
