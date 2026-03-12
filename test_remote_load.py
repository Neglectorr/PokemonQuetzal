import ctypes
import ctypes.wintypes
import sys
import time
import os

class COPYDATASTRUCT(ctypes.Structure):
    _fields_ = [
        ('dwData', ctypes.wintypes.WPARAM),
        ('cbData', ctypes.wintypes.DWORD),
        ('lpData', ctypes.c_void_p)
    ]

WM_COPYDATA = 0x004A
GBA_MAGIC = 0x47424101

def find_mgba_windows():
    hwnds = []
    def enum_cb(hwnd, lparam):
        length = ctypes.windll.user32.GetWindowTextLengthW(hwnd)
        if length > 0:
            buff = ctypes.create_unicode_buffer(length + 1)
            ctypes.windll.user32.GetWindowTextW(hwnd, buff, length + 1)
            title = buff.value
            if "mGBA" in title and "mGBA.exe" not in title: # Avoid the log console if it has one
                hwnds.append(hwnd)
        return True
    
    enum_proc = ctypes.WINFUNCTYPE(ctypes.c_bool, ctypes.wintypes.HWND, ctypes.wintypes.LPARAM)(enum_cb)
    ctypes.windll.user32.EnumWindows(enum_proc, 0)
    return hwnds

def send_rom_load(hwnd, rom_path):
    print(f"Sending ROM load request to HWND {hwnd}: {rom_path}")
    path_bytes = rom_path.encode('utf-16-le') + b'\x00\x00'
    cds = COPYDATASTRUCT()
    cds.dwData = GBA_MAGIC
    cds.cbData = len(path_bytes)
    cds.lpData = ctypes.cast(ctypes.create_string_buffer(path_bytes), ctypes.c_void_p)
    
    res = ctypes.windll.user32.SendMessageW(hwnd, WM_COPYDATA, 0, ctypes.byref(cds))
    print(f"Result: {res}")

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python test_remote_load.py <rom_path>")
        sys.exit(1)
    
    rom_path = os.path.abspath(sys.argv[1])
    windows = find_mgba_windows()
    if not windows:
        print("No mGBA windows found!")
        sys.exit(1)
    
    for hwnd in windows:
        send_rom_load(hwnd, rom_path)
