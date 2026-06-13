#include "BroadBandAmplifier.h"
#include "SignalComponent.h"
#include "signal.h"

//Opgave 3 d)

BroadBandAmplifier::BroadBandAmplifier(double amplification){
    this->amplification = amplification;
}

void BroadBandAmplifier::amplify(Signal& signal){
	for (auto& component : signal.signalComponents)
	{
		component.amplify(amplification);
	}

}