import pyaudio

def find_wasapi_loopback():
    p = pyaudio.PyAudio()
    wasapi_info = None
    
    # Find WASAPI Host API
    for i in range(p.get_host_api_count()):
        host_info = p.get_host_api_info_by_index(i)
        if "WASAPI" in host_info["name"]:
            wasapi_info = host_info
            break
            
    if not wasapi_info:
        print("WASAPI not found!")
        p.terminate()
        return

    print(f"Found WASAPI Host API at index {wasapi_info['index']}")
    
    # List all devices under WASAPI
    for i in range(p.get_device_count()):
        dev = p.get_device_info_by_index(i)
        if dev["hostApi"] == wasapi_info["index"]:
            # Check if it's a loopback (output) device
            # Typically these have maxInputChannels > 0 in WASAPI loopback mode
            print(f"Index {i}: {dev['name']}")
            print(f"  Input Channels: {dev['maxInputChannels']}, Output Channels: {dev['maxOutputChannels']}")
            print(f"  Default Sample Rate: {dev['defaultSampleRate']}")
            
    p.terminate()

if __name__ == "__main__":
    find_wasapi_loopback()
