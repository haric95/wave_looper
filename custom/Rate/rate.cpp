#include "rate.h"

using namespace daisysp;

void Rate::SetMultiplier(int multiplier)
{
    multiplier_ = multiplier;
}

float Rate::Process()
{
    float out;
    float phs = phasor_.Process();
    if(prevVal_ > phs)
    {
        bucket_ = (bucket_ + 1) % multiplier_;
    }
    prevVal_ = phs;
    return bucket_ + phs;
}
