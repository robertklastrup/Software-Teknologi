#include "Amplifier.h"
#include "BroadBandAmplifier.h"
#include "NarrowBandAmplifier.h"
#include "SignalComponent.h"
#include "Signal.h"
#include <iostream>


int main()
{
	//Opgave 3 f-1)
	Signal signal;
	signal.addComponent(2, 1000, 0);
	signal.addComponent(4, 2000, 0);
	signal.addComponent(6, 3000, 0);
	signal.addComponent(8, 4000, 0);

	std::string signal_string = signal.toString();
	std::cout << signal_string << std::endl;

	//Opgave 3 f-2)
	BroadBandAmplifier b (2);
	NarrowBandAmplifier n (10, 3000.00001, 2999.9999);

	b.amplify(signal);
	signal_string = signal.toString();
	std::cout << signal_string << std::endl;

	n.amplify(signal);
	signal_string = signal.toString();
	std::cout << signal_string << std::endl;

	return 0;
}
