#pragma once
#include <vector>

class time_series
{
public:
	void add(double);
	unsigned long long mean_duration() const;
	double mean_value() const;
private:
	std::vector<std::pair<long long, double>> series_;
};
