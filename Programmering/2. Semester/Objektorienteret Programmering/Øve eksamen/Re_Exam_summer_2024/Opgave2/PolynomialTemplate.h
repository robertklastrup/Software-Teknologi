#pragma once
#include <sstream>// denne skal v�re der til implementering af toString
//Opgave 2 a)
#include <string>
#include <vector>

template <typename T>
class Polynomial
{
public:
	Polynomial(const std::vector<T>& coefficients);
	T operator()(T value) const;
	Polynomial operator +(const Polynomial&) const;
	size_t order() const;
	size_t size() const;
	std::string toString() const;
private:
	
	std::vector<T> coefficients_;
};


template <typename T>
Polynomial<T>::Polynomial(const std::vector<T>& coefficients)
	: coefficients_(coefficients.empty() ? std::vector<T>{0} : coefficients)
{
}

template <typename T>
T Polynomial<T>::operator()(const T value) const
{
	T res = 0;
	T power(1);
	for (const auto& coefficient : coefficients_)
	{
		res = res + coefficient * power;
		power = power * value;
	}
	return res;
}

template <typename T>
Polynomial<T> Polynomial<T>::operator+(const Polynomial<T>& other) const
{
	const size_t maxSize = std::max(other.coefficients_.size(), coefficients_.size());
	std::vector<T> newCoefficients;
	for (size_t i = 0; i < maxSize; ++i)
	{
		const T value1 = (i < other.size()) ? other.coefficients_[i] : 0;
		const T value2 = (i < size()) ? coefficients_[i] : 0;
		newCoefficients.push_back(value1 + value2);
	}
	return {newCoefficients};
}

template <typename T>
size_t Polynomial<T>::order() const
{
	return coefficients_.size() - 1;
}

template <typename T>
size_t Polynomial<T>::size() const
{
	return coefficients_.size();
}

template <typename T>
std::string Polynomial<T>::toString() const
{
	std::ostringstream res;

	for (size_t i = 0; i < coefficients_.size(); ++i)
	{
		if (i > 0)
		{
			res << " + ";
		}
		res << coefficients_[i] << "*x^" << i;
	}
	return res.str();
}
