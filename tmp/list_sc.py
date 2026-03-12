import soundcard as sc

def list_soundcard():
    print("Listing all speakers...")
    speakers = sc.all_speakers()
    for i, s in enumerate(speakers):
        print(f"Speaker {i}: {s.name}")
        
    print("\nListing all microphones (including loopback)...")
    mics = sc.all_microphones(include_loopback=True)
    for i, m in enumerate(mics):
        print(f"Microphone {i}: {m.name} (Loopback: {m.isloopback})")

if __name__ == "__main__":
    list_soundcard()
