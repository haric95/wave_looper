#include "waveLooper.h"
#include "globals.h"

void WaveLooper::Init(int bpm)
{
    channels_[0].bars = 4;
    channels_[1].bars = 4;
    channels_[2].bars = 4;
    channels_[3].bars = 4;
    channels_[0].beats = 4;
    channels_[1].beats = 4;
    channels_[2].beats = 4;
    channels_[3].beats = 4;
    channels_[0].playhead.Init(masterClock_, channels_[0].bars * channels_[0].beats);
    channels_[1].playhead.Init(masterClock_, channels_[1].bars * channels_[1].beats);
    channels_[2].playhead.Init(masterClock_, channels_[2].bars * channels_[2].beats);
    channels_[3].playhead.Init(masterClock_, channels_[3].bars * channels_[3].beats);
    masterClock_.Init(constants::SAMPLE_RATE, bpm / 60);
    prev_ = 0;
}

float WaveLooper::Process() {
    return masterClock_.Process();
}

int WaveLooper::GetBars(int channel) {
    return channels_[channel].bars;
}

int WaveLooper::GetBeats(int channel) {
    return channels_[channel].beats;
}

void WaveLooper::SetBars(int channel, int bars) {
    channels_[channel].bars = bars;
}

void WaveLooper::SetBeats(int channel, int beats) {
    channels_[channel].beats = beats;
}

bool WaveLooper::Test() {
    float a = masterClock_.Process();
    bool newCycle = a < prev_;
    prev_ = a;
    return newCycle;
}

