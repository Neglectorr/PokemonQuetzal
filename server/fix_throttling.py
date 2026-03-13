import ctypes
from ctypes import wintypes
import sys
import time

# Windows Constants
PROCESS_POWER_THROTTLING = 4
PROCESS_POWER_THROTTLING_CURRENT_VERSION = 1
PROCESS_POWER_THROTTLING_EXECUTION_SPEED = 0x1

class PROCESS_POWER_THROTTLING_STATE(ctypes.Structure):
    _fields_ = [
        ("Version", wintypes.ULONG),
        ("ControlMask", wintypes.ULONG),
        ("StateMask", wintypes.ULONG),
    ]

def fix(pid):
    kernel32 = ctypes.windll.kernel32
    
    # 0x1F0FFF = PROCESS_ALL_ACCESS
    hProcess = kernel32.OpenProcess(0x1F0FFF, False, pid)
    if not hProcess:
        # Fallback to specific permissions
        hProcess = kernel32.OpenProcess(0x0200 | 0x0400 | 0x1000, False, pid)

    if not hProcess:
        print(f"FAILED to open process {pid}")
        return

    # 1. Disable Windows Power Throttling (Efficiency Mode)
    state = PROCESS_POWER_THROTTLING_STATE()
    state.Version = 1
    state.ControlMask = 1 # Execution Speed
    state.StateMask = 0   # Not limited
    
    res_throttle = kernel32.SetProcessInformation(
        hProcess,
        PROCESS_POWER_THROTTLING,
        ctypes.byref(state),
        ctypes.sizeof(state)
    )
    
    # 2. Set Priority to High (0x80)
    res_priority = kernel32.SetPriorityClass(hProcess, 0x00000080)
    
    # 3. Increase Thread Priority for the process-wide threads
    # (Optional but helpful for GBA cycles)
    
    kernel32.CloseHandle(hProcess)
    print(f"Fix applied to PID {pid}: ThrottleDisable={res_throttle}, HighPriority={res_priority}")

if __name__ == "__main__":
    if len(sys.argv) > 1:
        # Give mGBA a millisecond to initialize its window/timers
        time.sleep(0.5)
        fix(int(sys.argv[1]))
    else:
        print("Usage: python fix_throttling.py <PID>")
