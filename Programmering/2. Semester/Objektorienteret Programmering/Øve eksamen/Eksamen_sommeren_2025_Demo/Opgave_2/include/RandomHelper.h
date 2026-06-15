#pragma once
// Causes current thread to sleep for an amount of delay milliseconds
// where delay is uniformly distributed from 1-100 millis
void delay();

// Returns a random value that is normal distributed
// with mean 1 and standard deviation 1
double random_value();
