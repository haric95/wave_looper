#include "daisy_seed.h"
#include "globals.h"
#include "waveLooper.h"

// Use the daisy namespace to prevent having to type
// daisy:: before all libdaisy functions
using namespace daisy;

#define BLOCK_SIZE 64

// Declare a DaisySeed object called hardware
DaisySeed hardware;

WaveLooper looper = WaveLooper();

float test;

// DSP in here.
void AudioCallback(AudioHandle::InputBuffer in, AudioHandle::OutputBuffer out, size_t size) {
    looper.Process();
    test = looper.Test();
}

// Side effects in here
int main(void)
{    
    // Configure and Initialize the Daisy Seed
    // These are separate to allow reconfiguration of any of the internal
    // components before initialization.
    
    hardware.Init();
    hardware.SetLed(true);
    hardware.SetAudioBlockSize(BLOCK_SIZE); // number of samples handled per callback
	hardware.SetAudioSampleRate(SaiHandle::Config::SampleRate::SAI_48KHZ);
    hardware.StartLog(false);

    looper.Init(120);

	hardware.StartAudio(AudioCallback);

    // Loop forever
    while (1) {

    }
}
