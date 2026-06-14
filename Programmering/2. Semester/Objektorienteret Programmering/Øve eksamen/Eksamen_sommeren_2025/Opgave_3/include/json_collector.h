#pragma once

#include "data_collector.h"
#include <string>
#include <vector>

class json_collector : public data_collector{
public:
    json_collector(const std::string &value_name, double low, double high);

protected:
    std::vector <double> prepare()const;
    void collect(double value);
    bool  filter (double value)const;
    std::string  format(double value) const;
private:

    std::string value_name_;
    std::pair<double, double> range_;
    std::vector<double> data_;
};