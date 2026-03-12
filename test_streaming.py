import time
import struct
import sys
import os

def test_pipe(pipe_name):
    pipe_path = f"\\\\.\\pipe\\{pipe_name}"
    print(f"Connecting to pipe: {pipe_path}")
    
    try:
        # On Windows, we can just open the pipe like a file
        with open(pipe_path, 'rb') as f:
            print(f"Connected to {pipe_name}! Waiting for packets...")
            packet_count = 0
            start_time = time.time()
            
            has_video = False
            while packet_count < 1000 and not has_video:
                # Read header: Magic(4) + Type(1) + Size(4)
                header = f.read(9)
                if not header:
                    break
                
                magic, ptype, psize = struct.unpack('<IBI', header)
                if magic != 0x5354524D: # "STRM"
                    print(f"[{pipe_name}] Invalid magic: {hex(magic)}")
                    break
                
                # Read payload
                data = f.read(psize)
                packet_count += 1
                
                if ptype == 0:
                    has_video = True
                    width, height = struct.unpack('<II', data[:8])
                    print(f"[{pipe_name}] Received Video Packet: {width}x{height} ({psize} bytes)")
                
                if packet_count % 100 == 0:
                    ptype_str = "Video" if ptype == 0 else "Audio"
                    print(f"[{pipe_name}] Received {packet_count} packets. Last: {ptype_str} ({psize} bytes)")
            
            duration = time.time() - start_time
            print(f"[{pipe_name}] Test finished. Received {packet_count} packets in {duration:.2f}s.")
            return True
            
    except Exception as e:
        print(f"[{pipe_name}] Error: {e}")
        return False

if __name__ == "__main__":
    if len(sys.argv) > 2:
        # Test multiple pipes
        names = sys.argv[1:]
        for name in names:
            test_pipe(name)
    else:
        name = sys.argv[1] if len(sys.argv) > 1 else "mgba_stream"
        test_pipe(name)
