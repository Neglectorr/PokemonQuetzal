import pyaudio

def list_devices():
    p = pyaudio.PyAudio()
    print("Listing all audio devices...")
    for i in range(p.get_device_count()):
        dev = p.get_device_info_by_index(i)
        print(f"Index {i}: {dev['name']} (Channels: {dev['maxInputChannels']} in / {dev['maxOutputChannels']} out) - Host API: {p.get_host_api_info_by_index(dev['hostApi'])['name']}")
    p.terminate()

if __name__ == "__main__":
    list_devices()
