#pragma once
#include <chrono> // nedded in implementation
#include <stdexcept> // nedded in implementation
#include <vector>

//Opgave a)
template <typename T>
class time_series_template
{
public:
	void add(T);
	unsigned long long mean_duration() const;
	T mean_value() const;
private:
	std::vector<std::pair<long long, T>> series_;
};

template <typename T>
void time_series_template<T>::add(T value)
{
	const auto now = std::chrono::system_clock::now();
	auto time = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();
	series_.emplace_back(time, value);
}

template <typename T>
unsigned long long time_series_template<T>::mean_duration() const
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


template <typename T>
T time_series_template<T>::mean_value() const
{
	if (series_.empty())
	{
		throw std::length_error("Length of series must be at least 1");
	}
	T sum = series_[0].second;
	for (size_t i = 1; i < series_.size(); i++)
	{
		sum =sum+ series_[i].second;
	}
	return sum / static_cast<T>(series_.size());
}