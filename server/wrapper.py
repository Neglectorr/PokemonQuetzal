import sys
import os
import time
import struct
import threading
import win32gui
import win32ui
import win32con
import win32process
import win32api
import numpy as np
import cv2
import soundcard as sc
import ctypes

def get_hwnds_for_pid(pid):
    def callback(hwnd, hwnds):
        # On some server environments, IsWindowVisible can be unreliable or windows 
        # might be reported as invisible initially. We check dimensions instead.
        _, found_pid = win32process.GetWindowThreadProcessId(hwnd)
        if found_pid == pid:
            class_name = win32gui.GetClassName(hwnd)
            title = win32gui.GetWindowText(hwnd).lower()
            rect = win32gui.GetClientRect(hwnd)
            w, h = rect[2] - rect[0], rect[3] - rect[1]
            
            # Look for typical Qt/mGBA characteristics but be more lenient
            is_mgba = ("qt" in class_name.lower()) or ("mgba" in title) or (title == "")
            
            if is_mgba and w > 100 and h > 100:
                hwnds.append(hwnd)
        return True
    hwnds = []
    win32gui.EnumWindows(callback, hwnds)
    return hwnds

def capture_window(hwnd):
    # Get window bounds
    left, top, right, bottom = win32gui.GetWindowRect(hwnd)
    width = right - left
    height = bottom - top
    if width <= 0 or height <= 0:
        return None

    # mGBA window has a menu bar and borders. We should capture the client area.
    client_left, client_top, client_right, client_bottom = win32gui.GetClientRect(hwnd)
    client_width = client_right - client_left
    client_height = client_bottom - client_top
    if client_width <= 0 or client_height <= 0:
        return None

    hwndDC = win32gui.GetWindowDC(hwnd)
    mfcDC = win32ui.CreateDCFromHandle(hwndDC)
    saveDC = mfcDC.CreateCompatibleDC()
    
    saveBitMap = win32ui.CreateBitmap()
    # Capture exactly the client area
    saveBitMap.CreateCompatibleBitmap(mfcDC, client_width, client_height)
    saveDC.SelectObject(saveBitMap)
    
    # On Windows 10/11, 3 (PW_CLIENTONLY) is required for some apps, 
    # but 2 (PW_RENDERFULLCONTENT) is often more reliable for Qt 5 in Session 0.
    try:
        result = ctypes.windll.user32.PrintWindow(hwnd, saveDC.GetSafeHdc(), 2)
    except:
        result = ctypes.windll.user32.PrintWindow(hwnd, saveDC.GetSafeHdc(), 0)
        
    bmpinfo = saveBitMap.GetInfo()
    bmpstr = saveBitMap.GetBitmapBits(True)
    
    img = np.frombuffer(bmpstr, dtype='uint8')
    img.shape = (client_height, client_width, 4)
    
    win32gui.DeleteObject(saveBitMap.GetHandle())
    saveDC.DeleteDC()
    mfcDC.DeleteDC()
    win32gui.ReleaseDC(hwnd, hwndDC)

    if result != 1:
        return None
        
    # Extract the GBA 1.5 Aspect Ratio bounding box.
    # mGBA keeps the menu bar at the top, so the game is generally horizontally centered and bottom aligned.
    gw = client_width
    gh = int(gw / 1.5)
    if gh > client_height:
        gh = client_height
        gw = int(gh * 1.5)
    
    start_x = (client_width - gw) // 2
    # Vertically bottom align to strip the top menu bar, but keep any pillarboxing stripped.
    start_y = client_height - gh 
    
    img = img[start_y:start_y+gh, start_x:start_x+gw]

    # Resize to exactly 240x160 to save bandwidth
    img = cv2.resize(img, (240, 160), interpolation=cv2.INTER_NEAREST)

    # Convert BGRA to BGR
    img = cv2.cvtColor(img, cv2.COLOR_BGRA2BGR)
    
    # Epilepsy safety: drop pure black frames (e.g. if PrintWindow failed to capture content)
    if np.max(img) == 0:
        return None
        
    return img

# GBA Button map to Virtual Keys (we define mGBA default keyboard mapping)
# Default mGBA keys: Up=Up, Down=Down, Left=Left, Right=Right, A=X, B=Z, Start=Enter, Select=Backspace, L=A, R=S
VK_MAP = {
    'Up': win32con.VK_UP,
    'Down': win32con.VK_DOWN,
    'Left': win32con.VK_LEFT,
    'Right': win32con.VK_RIGHT,
    'A': 0x58, # X
    'B': 0x5A, # Z
    'Start': win32con.VK_RETURN,
    'Select': win32con.VK_BACK,
    'L': 0x41, # A
    'R': 0x53, # S
    'Shift': win32con.VK_LSHIFT, # Use LSHIFT specifically
    'F1': win32con.VK_F1
}

def send_key(hwnd, key_name, is_down):
    if key_name not in VK_MAP:
        return
    vk = VK_MAP[key_name]
    
    # Map virtual key to scan code
    scan_code = win32api.MapVirtualKey(vk, 0)
    
    # Build lParam: repeat count(16), scan code(8), extended(1), reserved(1), context(1), prev state(1), transition(1)
    lParam = 0x0001 | (scan_code << 16)
    if not is_down:
        lParam |= (1 << 30) # Previous state was down
        lParam |= (1 << 31) # Transition state is up
        msg = win32con.WM_KEYUP
    else:
        msg = win32con.WM_KEYDOWN
    
    # Some apps (Qt) are picky and need scan codes
    win32api.PostMessage(hwnd, msg, vk, lParam)

def input_thread(hwnds_dict):
    script_dir = os.path.dirname(os.path.abspath(__file__))
    log_path = os.path.join(script_dir, '..', 'tmp', 'wrapper_input.log')
    with open(log_path, "a") as f:
        f.write(f"--- Input thread started at {time.ctime()} ---\n")
        f.flush()
        
    while True:
        try:
            line = sys.stdin.readline()
            if not line: break
            line = line.strip()
            if not line: continue
            
            with open(log_path, "a") as f:
                f.write(f"Received: {line}\n")
                f.flush()
                
            # Format: Slot,Btn,1
            parts = line.split(',')
            if len(parts) == 3:
                slot = int(parts[0])
                btn = parts[1]
                state = parts[2] == '1'
                if slot in hwnds_dict:
                    send_key(hwnds_dict[slot], btn, state)
        except Exception as e:
            with open(log_path, "a") as f:
                f.write(f"Error in input_thread: {e}\n")
                f.flush()
            break

def audio_thread():
    try:
        # Get the default speaker
        speaker = sc.default_speaker()
        if not speaker:
            sys.stderr.write("Audio Thread: No default speaker found. Audio capture disabled.\n")
            return

        # Attempt to get loopback microphone
        loopback = None
        try:
            for m in sc.all_microphones(include_loopback=True):
                if m.isloopback and speaker.name in m.name:
                    loopback = m
                    break
        except:
            pass
        
        if not loopback:
            try:
                loopback = speaker.microphone
            except:
                pass
            
        if not loopback:
            sys.stderr.write("Audio Thread: No loopback device found. Audio capture disabled.\n")
            return
            
        sys.stderr.write(f"Starting audio capture on: {loopback.name}\n")
        
        # Capture 44100, Mono. soundcard captures as float32 [-1, 1].
        with loopback.recorder(samplerate=44100, channels=1) as recorder:
            while True:
                data = recorder.record(numframes=1024)
                if data is None: continue
                # Convert float32 to int16
                audio_int16 = (data * 32767).astype(np.int16)
                audio_bytes = audio_int16.tobytes()
                
                # Write to stdout as Slot 0
                # Header: [Slot 0 (1b)][Size (4b LE)]
                sys.stdout.buffer.write(struct.pack('<BI', 0, len(audio_bytes)))
                sys.stdout.buffer.write(audio_bytes)
                sys.stdout.buffer.flush()
    except Exception as e:
        sys.stderr.write(f"Audio Thread Error: {e}\n")

def main():
    if len(sys.argv) < 2:
        sys.stderr.write("Usage: python wrapper.py <PID> [expected_count]\n")
        sys.exit(1)
        
    pid = int(sys.argv[1])
    expected_count = int(sys.argv[2]) if len(sys.argv) > 2 else 4
    no_capture = "--no-capture" in sys.argv
    
    sys.stderr.write(f"Looking for {expected_count} windows with PID {pid}... (no_capture={no_capture})\n")
    
    # Wait for windows to appear, or timeout after 10 seconds
    hwnds_dict = {}
    script_dir = os.path.dirname(os.path.abspath(__file__))
    log_path = os.path.join(script_dir, '..', 'tmp', 'wrapper_input.log')
    with open(log_path, "a") as f:
        f.write(f"--- Window Detection started for PID {pid} ---\n")
        
    for _ in range(100):
        hwnds = get_hwnds_for_pid(pid)
        
        # Sort by HWND to ensure stable assignment if titles are identical
        hwnds.sort()
        
        hwnds_dict = {}
        for i, h in enumerate(hwnds):
            title = win32gui.GetWindowText(h).lower()
            rect = win32gui.GetClientRect(h)
            area = (rect[2] - rect[0]) * (rect[3] - rect[1])
            
            # Default slot by order
            slot = i + 1
            # Override if title specifically mentions player
            if "player 2" in title: slot = 2
            elif "player 3" in title: slot = 3
            elif "player 4" in title: slot = 4
            
            # Keep only the window for this slot, prioritize larger area if multiple candidates
            if slot <= expected_count:
                if slot not in hwnds_dict or area > hwnds_dict[slot]['area']:
                    hwnds_dict[slot] = {'hwnd': h, 'area': area, 'title': title}
                    
        if len(hwnds_dict) >= expected_count:
            break
        time.sleep(0.5)
        
    with open(log_path, "a") as f:
        f.write(f"Found {len(hwnds_dict)} windows: {[(s, d['title']) for s, d in hwnds_dict.items()]}\n")
        f.flush()
        
    if not hwnds_dict:
        sys.stderr.write(f"Could not find mGBA windows for PID {pid}\n")
        sys.exit(1)
        
    # Build final structures mapping exactly 1 hwnd per slot
    final_dict = {slot: data['hwnd'] for slot, data in hwnds_dict.items()}
    multi_hwnds = sorted(list(final_dict.items()), key=lambda x: x[0])
    
    sys.stderr.write(f"Found {len(multi_hwnds)} mGBA windows: {final_dict}\n")
    
    # Start input listening thread
    t = threading.Thread(target=input_thread, args=(final_dict,), daemon=True)
    t.start()
    
    # Audio capture REMOVED as requested (avoiding global mixing for now)
    
    # Target 30 FPS to save CPU and bandwidth
    frame_time = 1.0 / 30.0
    
    if not no_capture:
        while True:
            start_t = time.time()
            
            all_closed = True
            for slot, h in multi_hwnds:
                if not win32gui.IsWindow(h):
                    continue
                all_closed = False
                
                img = capture_window(h)
                if img is not None:
                    # Encode PNG for lossless pixel art quality
                    encode_param = [int(cv2.IMWRITE_PNG_COMPRESSION), 1]
                    result, encimg = cv2.imencode('.png', img, encode_param)
                    if result:
                        data = encimg.tobytes()
                        # Write header: [Slot (1 byte)][Size (4 bytes LE)]
                        sys.stdout.buffer.write(struct.pack('<BI', slot, len(data)))
                        sys.stdout.buffer.write(data)
                        sys.stdout.buffer.flush()
            
            if all_closed:
                sys.stderr.write("All mGBA windows closed.\n")
                break
                
            elapsed = time.time() - start_t
            sleep_time = frame_time - elapsed
            if sleep_time > 0:
                time.sleep(sleep_time)
    else:
        # Input-only mode: just keep the process alive while windows exist
        sys.stderr.write("Input-only mode active. Skipping capture loop.\n")
        while True:
            all_closed = True
            for slot, h in multi_hwnds:
                if win32gui.IsWindow(h):
                    all_closed = False
                    break
            if all_closed:
                sys.stderr.write("All mGBA windows closed (input-only).\n")
                break
            time.sleep(1.0)

if __name__ == '__main__':
    main()
