#pragma once
#include "Amplifier.h"
//Opgave 3 c)
class NarrowBandAmplifier : public Amplifier{
    private:
        double amplification;
        double upperFrequencyLimit;
        double LowerFrequencyLimit;
    public:
        NarrowBandAmplifier(double amplification, double upperFrequencyLimit, double LowerFrequency_limit);
        void amplify(Signal& signal);
};