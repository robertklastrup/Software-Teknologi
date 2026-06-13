#include "BroadBandAmplifier.h"
#include "SignalComponent.h"
#include "signal.h"
#include "NarrowBandAmplifier.h"


//Opgave 3 e)

NarrowBandAmplifier::NarrowBandAmplifier(double amplification, double upperFrequencyLimit, double LowerFrequency_limit){
    this -> amplification = amplification;
    this -> upperFrequencyLimit = upperFrequencyLimit;
    this -> LowerFrequencyLimit = LowerFrequency_limit;
}
void NarrowBandAmplifier::amplify(Signal& signal){
    
    for (auto& component : signal.signalComponents)
	{
        if (component.get_frequency() >= LowerFrequencyLimit && component.get_frequency() <= upperFrequencyLimit){
            component.amplify(amplification);
        }
        else{
            continue;
        }
	}
}