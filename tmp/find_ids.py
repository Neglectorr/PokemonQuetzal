
import win32gui
import win32con
import win32process
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

def test_ids(pid):
    hwnds = get_hwnds_for_pid(pid)
    if not hwnds:
        print("mGBA not found")
        return
    hwnd = hwnds[0]
    
    # Try ID range. mGBA (Qt) often maps actions to IDs.
    # Start with a known range.
    for cmd_id in range(40000, 40100):
        pre_count = len(get_hwnds_for_pid(pid))
        win32gui.PostMessage(hwnd, win32con.WM_COMMAND, cmd_id, 0)
        time.sleep(0.5)
        post_count = len(get_hwnds_for_pid(pid))
        
        if post_count > pre_count:
            print(f"FOUND 'New Window' ID: {cmd_id}")
            return cmd_id
        
        # Also check if a dialog appeared (dialogs might have same PID but different characteristics)
        # But for now, window count is easiest.
    print("Done testing range.")

if __name__ == "__main__":
    test_ids(int(sys.argv[1]))
