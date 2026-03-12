import win32gui
import win32process

def get_mgba_windows():
    hwnds = []
    def cb(h, _):
        text = win32gui.GetWindowText(h)
        if "mGBA" in text:
            hwnds.append((h, text))
        return True
    win32gui.EnumWindows(cb, None)
    return hwnds

if __name__ == "__main__":
    wins = get_mgba_windows()
    print(f"Found {len(wins)} mGBA windows:")
    for h, t in wins:
        print(f"Handle: {h}, Title: '{t}'")
