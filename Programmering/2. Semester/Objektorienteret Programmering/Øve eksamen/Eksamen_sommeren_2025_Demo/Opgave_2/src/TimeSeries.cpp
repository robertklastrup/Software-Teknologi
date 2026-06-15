#include "TimeSeries.h"

#include <chrono>
#include <stdexcept>

void time_series::add(double value)
{
	const auto now = std::chrono::system_clock::now();
	auto time = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();
	series_.emplace_back(time, value);
}

unsigned long long time_series::mean_duration() const
{
	if (series_.size() < 2)
	{
		throw std::length_error("Length of series must be at least 2");
	}
	long long duration_sum = 0;
	for (size_t i = 1; i < series_.size(); i++)
	{
		duration_sum += series_[i].first - series_[i - 1].first;
	}
	return duration_sum / series_.size() - 1;
}

double time_series::mean_value() const
{
	if (series_.empty())
	{
		throw std::length_error("Length of series must be at least 1");
	}
	double sum = series_[0].second;
	for (size_t i = 1; i < series_.size(); i++)
	{
		sum =sum+ series_[i].second;
	}
	return sum / static_cast<double>(series_.size());
}
