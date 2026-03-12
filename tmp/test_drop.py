
import win32gui
import win32con
import win32api
import win32process
import ctypes
import ctypes.wintypes
import time
import subprocess
import os

# Structure for DROPFILES
class DROPFILES(ctypes.Structure):
    _fields_ = [
        ("pFiles", ctypes.wintypes.DWORD),
        ("pt", ctypes.wintypes.POINT),
        ("fNC", ctypes.wintypes.BOOL),
        ("fWide", ctypes.wintypes.BOOL),
    ]

def get_hwnds_for_pid(pid):
    hwnds = []
    def cb(h, _):
        _, p = win32process.GetWindowThreadProcessId(h)
        if p == pid and win32gui.GetClientRect(h)[2] > 100:
            hwnds.append(h)
        return True
    win32gui.EnumWindows(cb, None)
    return hwnds

def post_drop_files(hwnd, files):
    # files is a list of strings
    # We need to create a buffer: DROPFILES struct + NULL-separated file list + double-NULL
    
    joined_files = "\0".join(files) + "\0\0"
    wide_files = joined_files.encode("utf-16le")
    
    df = DROPFILES()
    df.pFiles = ctypes.sizeof(DROPFILES)
    df.pt = ctypes.wintypes.POINT(0, 0)
    df.fNC = False
    df.fWide = True
    
    buffer = bytes(df) + wide_files
    
    # We need to allocate memory for the drop files
    # Actually, for PostMessage(WM_DROPFILES), the wParam must be a handle to a DROPFILES structure.
    # This usually means GlobalAlloc(GMEM_SHARE).
    
    # Setup kernel32 types
    kernel32 = ctypes.windll.kernel32
    user32 = ctypes.windll.user32
    
    kernel32.GlobalAlloc.restype = ctypes.wintypes.HGLOBAL
    kernel32.GlobalAlloc.argtypes = [ctypes.wintypes.UINT, ctypes.c_size_t]
    
    kernel32.GlobalLock.restype = ctypes.c_void_p
    kernel32.GlobalLock.argtypes = [ctypes.wintypes.HGLOBAL]
    
    kernel32.GlobalUnlock.restype = ctypes.wintypes.BOOL
    kernel32.GlobalUnlock.argtypes = [ctypes.wintypes.HGLOBAL]
    
    kernel32.GlobalFree.restype = ctypes.wintypes.HGLOBAL
    kernel32.GlobalFree.argtypes = [ctypes.wintypes.HGLOBAL]
    
    # Use user32.PostMessage directly to avoid win32gui/api int-size issues
    user32.PostMessageW.restype = ctypes.wintypes.BOOL
    user32.PostMessageW.argtypes = [ctypes.wintypes.HWND, ctypes.wintypes.UINT, ctypes.wintypes.WPARAM, ctypes.wintypes.LPARAM]
    
    hGlobal = kernel32.GlobalAlloc(0x0042, len(buffer)) # GMEM_MOVEABLE | GMEM_SHARE
    if not hGlobal:
        print("GlobalAlloc failed")
        return False
        
    pGlobal = kernel32.GlobalLock(hGlobal)
    if not pGlobal:
        print("GlobalLock failed")
        kernel32.GlobalFree(hGlobal)
        return False
        
    ctypes.memmove(pGlobal, buffer, len(buffer))
    kernel32.GlobalUnlock(hGlobal)
    
    # WM_DROPFILES = 0x0233
    if not user32.PostMessageW(hwnd, 0x0233, hGlobal, 0):
        print("PostMessage failed")
        kernel32.GlobalFree(hGlobal)
        return False
    return True

def main():
    print("STEP 1: Starting mGBA...")
    mgba_exe = r"c:\PassionProjects\GBAEmu\PokemonQuetzal\mgba_native\mGBA-0.10.3-win64\mGBA.exe"
    proc = subprocess.Popen([mgba_exe])
    time.sleep(4)
    pid = proc.pid
    
    hwnd = get_hwnds_for_pid(pid)[0]
    print(f"Target HWND: {hwnd}")

    print("\nSTEP 2: Posting WM_DROPFILES...")
    rom_path = os.path.abspath(r"c:\PassionProjects\GBAEmu\PokemonQuetzal\roms\QuetzalEnglishAlpha8v4.gba")
    if post_drop_files(hwnd, [rom_path]):
        print(f"Sent drop message for {rom_path}")
    else:
        print("Failed to send message.")

    print("Waiting 5s for ROM load...")
    time.sleep(5)
    
    final_title = win32gui.GetWindowText(hwnd)
    print(f"Final Title: '{final_title}'")
    
    if "Quetzal" in final_title:
        print("\n🏆 SUCCESS! ROM loaded blindly via WM_DROPFILES.")
    else:
        print("\n❌ FAILED. Title did not change.")

    proc.terminate()

if __name__ == "__main__":
    main()
