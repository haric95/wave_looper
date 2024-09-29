#include "daisysp.h";
#include "globals.h";

static daisysp::Phasor beatClock;

float clocks()
{
    beatClock.Init(SAMPLE_RATE);

    return beatClock.Process();
}

