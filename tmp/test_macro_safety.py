import subprocess
import os
import time

def test_macro_with_wrong_pid():
    # Notepad or something similar is likely running or can be spawned
    try:
        notepad = subprocess.Popen(['notepad.exe'])
        pid = notepad.pid
        print(f"Spawned Notepad with PID: {pid}")
        time.sleep(2)
        
        # Run the macro against Notepad's PID
        macro_path = os.path.join('server', 'spawn_multiplayer.py')
        result = subprocess.run(['python', macro_path, str(pid)], capture_output=True, text=True)
        
        print("Macro Output:", result.stdout)
        print("Macro Error:", result.stderr)
        
        if "ABORT: PID" in result.stderr and "is NOT mGBA" in result.stderr:
            print("SUCCESS: Macro correctly identified the process is not mGBA and aborted.")
        else:
            print("FAILURE: Macro did not abort as expected.")
            
        notepad.terminate()
    except Exception as e:
        print(f"Test failed due to exception: {e}")

if __name__ == '__main__':
    test_macro_with_wrong_pid()
