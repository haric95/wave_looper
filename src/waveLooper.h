#pragma once
#ifndef DSY_LOOPER_H
#define DSY_LOOPER_H
#ifdef __cplusplus

#include "globals.h"
#include "../DaisySP/Source/Control/phasor.h"
#include "../custom/Rate/rate.h"
#include "globals.h"

float DSY_SDRAM_BSS channel1Buffer[constants::CHANNEL_LENGTH_S * constants::SAMPLE_RATE];
float DSY_SDRAM_BSS channel2Buffer[constants::CHANNEL_LENGTH_S * constants::SAMPLE_RATE];
float DSY_SDRAM_BSS channel3Buffer[constants::CHANNEL_LENGTH_S * constants::SAMPLE_RATE];
float DSY_SDRAM_BSS channel4Buffer[constants::CHANNEL_LENGTH_S * constants::SAMPLE_RATE];

struct Channel {
  int bars;
  int beats;
  int loopEnd;
  float *buffer;
  Rate playhead;
};


/** Main Wave Looper Class
*/
class WaveLooper
{
  public:
    WaveLooper() {}
    ~WaveLooper() {}
    /** Initializes the 4 Channel wave looper
     * Takes initial BPM argument
     * 
    */
    void Init(int bpm);
    void Process();
    int GetBars(int channel);
    int GetBeats(int channel);
    void SetBeats(int channel, int beats);
    void SetBars(int channel, int bars);
    void SetBPM(int bpm);
    bool GetLedStatus();
    float Test();

  private:
    int bpm_;
    bool litLed_;
    float prev_;
    daisysp::Phasor masterClock_;
    Channel channels_[4];
};
#endif
#endif
