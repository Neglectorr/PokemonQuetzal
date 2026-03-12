import sys
import win32gui
import win32process

pid = int(sys.argv[1]) if len(sys.argv) > 1 else None
print(f"Target PID: {pid}")

hwnds = []
win32gui.EnumWindows(lambda h, l: l.append(h), hwnds)

for h in hwnds:
    if "mGBA" in win32gui.GetWindowText(h):
        tid, found_pid = win32process.GetWindowThreadProcessId(h)
        print(f"HWND: {h}, Title: {win32gui.GetWindowText(h)}, PID: {found_pid}, TID: {tid}, Matches target? {found_pid == pid}")
