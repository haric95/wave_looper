#pragma once
#ifndef DSY_LOOPER_H
#define DSY_LOOPER_H
#ifdef __cplusplus

#include "globals.h"
#include "../DaisySP/Source/Control/phasor.h"
#include "../custom/Rate/rate.h"
#include "globals.h"

struct Channel {
  int bars;
  int beats;
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
    float Process();
    int GetBars(int channel);
    int GetBeats(int channel);
    void SetBeats(int channel, int beats);
    void SetBars(int channel, int bars);
    bool Test();

  private:
    int bpm_;
    float prev_;
    daisysp::Phasor masterClock_;
    Channel channels_[4];
};
#endif
#endif
