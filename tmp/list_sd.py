import sounddevice as sd

def list_wasapi_loopback():
    devices = sd.query_devices()
    print("Listing WASAPI devices with loopback potential...")
    for i, dev in enumerate(devices):
        # We look for output devices in WASAPI host api
        host_api = sd.query_hostapis(dev['hostapi'])['name']
        if "WASAPI" in host_api:
            print(f"Index {i}: {dev['name']}")
            print(f"  Max Inputs: {dev['max_input_channels']}, Max Outputs: {dev['max_output_channels']}")
            # In sounddevice, loopback devices are often the output ones
            # used as input.
            
if __name__ == "__main__":
    list_wasapi_loopback()
