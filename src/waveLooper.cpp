#include "daisy_seed.h"
#include "waveLooper.h"
#include "globals.h"

void WaveLooper::Init(int bpm)
{
    bpm_ = bpm;
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
    channels_[0].buffer = channel1Buffer;
    channels_[1].buffer = channel2Buffer;
    channels_[2].buffer = channel3Buffer;
    channels_[3].buffer = channel4Buffer;
    masterClock_.Init(constants::SAMPLE_RATE, bpm / 60);
    prev_ = 0;
}

void WaveLooper::Process() {
    float cycle = masterClock_.Process();
    litLed_ = cycle <= 0.1;
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

void WaveLooper::SetBPM(int bpm) {
    bpm_ = std::min(std::max(constants::MIN_BPM, bpm), constants::MAX_BPM); 
}

float WaveLooper::Test() {
    return *(channels_[0].buffer);
}
