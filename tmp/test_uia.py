
from pywinauto.application import Application
import win32gui
import win32process
import time
import subprocess
import os

def main():
    print("STEP 1: Starting mGBA...")
    mgba_path = r"c:\PassionProjects\GBAEmu\PokemonQuetzal\mgba_native\mGBA-0.10.3-win64\mGBA.exe"
    proc = subprocess.Popen([mgba_path])
    time.sleep(4)
    pid = proc.pid

    print("\nSTEP 2: Starting Notepad and giving it focus...")
    notepad = subprocess.Popen(["notepad.exe"])
    time.sleep(2)
    fg = win32gui.GetForegroundWindow()
    print(f"Foreground Window HWND: {fg}, Title: '{win32gui.GetWindowText(fg)}'")

    print("\nSTEP 3: Attempting UIA interaction with mGBA...")
    try:
        app = Application(backend="uia").connect(process=pid)
        main_win = app.window(title_re=".*mGBA.*")
        
        # Try to find the menu item
        print("Searching for 'New multiplayer window'...")
        # In mGBA, it's under File -> New multiplayer window
        # We might need to expand the menu first or just call the action.
        menu_item = main_win.menu_select("File->New multiplayer window")
        print("Success? Menu selected.")
    except Exception as e:
        print(f"FAILED UIA: {e}")
        print("Attempting direct action find...")
        try:
           # Alternative: find by name
           app.window(title_re=".*mGBA.*").child_window(title="New multiplayer window", control_type="MenuItem").invoke()
           print("Success? Invoked via child_window.")
        except Exception as e2:
           print(f"FAILED direct invoke: {e2}")

    time.sleep(5)
    
    # Check window count
    hwnds = []
    def cb(h, _):
        _, p = win32process.GetWindowThreadProcessId(h)
        if p == pid:
            rect = win32gui.GetClientRect(h)
            if rect[2]-rect[0] > 100: hwnds.append(h)
        return True
    win32gui.EnumWindows(cb, None)
    print(f"\nFinal mGBA windows: {len(hwnds)}")
    
    if len(hwnds) > 1:
        print("\n🏆 SUCCESS! UIA triggered window spawn blindly.")
    else:
        print("\n❌ FAILED. UIA did not work without focus.")

    # proc.terminate()
    # notepad.terminate()

if __name__ == "__main__":
    main()
