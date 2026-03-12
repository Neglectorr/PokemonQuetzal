import sys
from pywinauto import Application

def inspect_mgba(pid):
    app = Application(backend="uia").connect(process=pid)
    window = app.window(title_re=".*mGBA.*")
    print("Dumping Control Identifiers for PID:", pid)
    window.print_control_identifiers()

if __name__ == '__main__':
    inspect_mgba(int(sys.argv[1]))
