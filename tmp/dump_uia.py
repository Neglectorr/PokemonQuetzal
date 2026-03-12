
from pywinauto.application import Application
import sys
import time

def dump_uia_menu(pid):
    try:
        app = Application(backend="uia").connect(process=pid, timeout=10)
        win = app.window(title_re=".*mGBA.*")
        
        print("Dumping Menu Structure...")
        # Try to find the menu bar and items
        try:
            menu_bar = win.menu_bar()
            for menu in menu_bar.items():
                print(f"Menu: {menu.text()}")
                # Expand and list subitems if possible
                try:
                    menu.select()
                    time.sleep(0.5)
                    for sub in menu.items():
                        print(f"  Sub: {sub.text()}")
                        if "recent" in sub.text().lower():
                            sub.select()
                            time.sleep(0.5)
                            for r in sub.items():
                                print(f"    Recent: {r.text()}")
                except:
                    pass
        except Exception as e:
            print(f"Error accessing menu: {e}")
            
        print("\nFull control identifiers:")
        win.print_control_identifiers()
        
    except Exception as e:
        print(f"Failed to connect or dump: {e}")

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python dump_uia.py <pid>")
    else:
        dump_uia_menu(int(sys.argv[1]))
