#pragma once

#include <set>
#include "data_collector.h"

class unique_sorted_collector : public data_collector{

protected:
    std::vector <double> prepare()const;
    void collect(double value);
    virtual bool  filter (double value)const = 0;
    virtual std::string  format(double value) const = 0;

private:
    std::set<double> data_;
};