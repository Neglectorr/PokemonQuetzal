
from pywinauto.application import Application
import sys
import time
import win32gui
import win32process

def main():
    print("STEP 1: Starting mGBA...")
    mgba_exe = r"c:\PassionProjects\GBAEmu\PokemonQuetzal\mgba_native\mGBA-0.10.3-win64\mGBA.exe"
    import subprocess
    proc = subprocess.Popen([mgba_exe])
    time.sleep(4)
    pid = proc.pid
    
    print("STEP 2: Connecting with UIA...")
    app = Application(backend="uia").connect(process=pid)
    win = app.window(title_re=".*mGBA.*")
    
    print("Attempting to click File menu...")
    try:
        # Some Qt apps don't have a standard menu bar in UIA.
        # Let's try to find anything with 'File'
        file_menu = win.child_window(title="File", control_type="MenuItem")
        file_menu.click_input() # This needs focus, but let's see if it works locally
        time.sleep(1)
        
        print("Dumping all visible windows in process...")
        # After clicking, the menu might be a new window
        for w in app.windows():
            print(f"Window: {w.window_text()}, Class: {w.class_name()}")
            w.print_control_identifiers()
            
    except Exception as e:
        print(f"Error: {e}")
        print("Falling back to print_control_identifiers on main window...")
        win.print_control_identifiers()

    proc.terminate()

if __name__ == "__main__":
    main()
