import ctypes
from ctypes import wintypes
import sys

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
    
    # PROCESS_ALL_ACCESS (0x1F0FFF)
    PROCESS_ALL_ACCESS = 0x000F0000 | 0x00100000 | 0xFFFF
    
    hProcess = kernel32.OpenProcess(PROCESS_ALL_ACCESS, False, pid)
    if not hProcess:
        # Try with common user permissions if ALL_ACCESS fails
        PROCESS_SET_INFORMATION = 0x0200
        PROCESS_QUERY_LIMITED_INFORMATION = 0x1000
        hProcess = kernel32.OpenProcess(PROCESS_SET_INFORMATION | PROCESS_QUERY_LIMITED_INFORMATION, False, pid)

    if not hProcess:
        print(f"FAILED to open process {pid}")
        return

    # 1. Disable Windows Power Throttling (Efficiency Mode)
    # This prevents the 10 FPS cap on background apps
    state = PROCESS_POWER_THROTTLING_STATE()
    state.Version = PROCESS_POWER_THROTTLING_CURRENT_VERSION
    state.ControlMask = PROCESS_POWER_THROTTLING_EXECUTION_SPEED
    state.StateMask = 0 # SPEED is NOT limited
    
    res_throttle = kernel32.SetProcessInformation(
        hProcess,
        PROCESS_POWER_THROTTLING,
        ctypes.byref(state),
        ctypes.sizeof(state)
    )
    
    # 2. Set Highest Priority Class
    # HIGH_PRIORITY_CLASS = 0x00000080
    res_priority = kernel32.SetPriorityClass(hProcess, 0x00000080)
    
    kernel32.CloseHandle(hProcess)
    print(f"Fix results for PID {pid}: ThrottlingDisable={res_throttle}, HighPriority={res_priority}")

if __name__ == "__main__":
    if len(sys.argv) > 1:
        fix(int(sys.argv[1]))
    else:
        print("Usage: python fix_throttling.py <PID>")
