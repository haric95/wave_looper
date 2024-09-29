#pragma once
#ifndef DSY_RATE_H
#define DSY_RATE_H
#ifdef __cplusplus

#include "../../lib/DaisySP/Source/Control/phasor.h"

/** Recieves a Phasor object and time scales it by a positive integer multiplier.

*/
class Rate
{
  public:
    Rate() {}
    ~Rate() {}
    /** Initializes the Rate module
     * Recieves two init argument of a phasor and a multiplier
    */
    inline void Init(daisysp::Phasor phasor, int multiplier)
    {
        phasor_ = phasor;
        multiplier_ = multiplier;
        bucket_ = 0;
        prevVal_ = 0;

    }

    /** processes the associated Phasor and return it's value at the multiplied rate
    */
    float Process();


    /** Sets frequency of the Phasor in Hz
    */
    void SetMultiplier(int multiplier);

  private:
    daisysp::Phasor phasor_;
    int multiplier_, bucket_;
    float prevVal_;
};
#endif
#endif
