import win32api
import win32process
import win32con
import ctypes
from ctypes import wintypes
import sys

# Windows constant for Power Throttling
ProcessPowerThrottling = 4

class PROCESS_POWER_THROTTLING_STATE(ctypes.Structure):
    _fields_ = [
        ("Version", wintypes.ULONG),
        ("ControlMask", wintypes.ULONG),
        ("StateMask", wintypes.ULONG),
    ]

def disable_throttling(pid):
    try:
        handle = win32api.OpenProcess(win32con.PROCESS_SET_INFORMATION | win32con.PROCESS_QUERY_INFORMATION | win32con.PROCESS_ALL_ACCESS, False, pid)
        if not handle:
            print(f"Could not open process {pid}")
            return
        
        # Disable Efficiency Mode (Power Throttling)
        state = PROCESS_POWER_THROTTLING_STATE()
        state.Version = 1 
        state.ControlMask = 1 
        state.StateMask = 0 
        
        kernel32 = ctypes.windll.kernel32
        res = kernel32.SetProcessInformation(
            int(handle), 
            ProcessPowerThrottling, 
            ctypes.byref(state), 
            ctypes.sizeof(state)
        )
        
        # Set priority to HIGH
        win32process.SetPriorityClass(handle, win32process.HIGH_PRIORITY_CLASS)
        
        print(f"Successfully disabled Windows Throttling for PID {pid}. (Result: {res})")
        win32api.CloseHandle(handle)
    except Exception as e:
        print(f"Error fixing PID {pid}: {e}")

if __name__ == "__main__":
    if len(sys.argv) > 1:
        disable_throttling(int(sys.argv[1]))
    else:
        print("Usage: python fix_throttling.py <PID>")
