#include "RandomHelper.h"

#include <chrono>
#include <random>
#include <thread>
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<unsigned long long> time_dist(1, 100);
std::normal_distribution<> value_dist(1, 1);

void delay()
{
	const auto delay = time_dist(gen);
	std::this_thread::sleep_for(std::chrono::milliseconds(delay));
}

double random_value()
{
	return value_dist(gen);
}
