#include "json_collector.h"

json_collector::json_collector(const std::string &value_name, double low, double high) : value_name_(value_name),
                                                                                         range_(std::pair(low, high)) {}



std::vector <double>  json_collector::prepare()const{
    return data_;
}

void json_collector::collect(double value){
    data_.push_back (value);
}

bool  json_collector::filter (double value)const{
    if (value >= range_.first && value <= range_.second){
        return true;
    }
    else{
        return false;
    }
}

std::string  json_collector::format(double value) const{
    std::string v = std::string("{") + "\n" + "\"" + value_name_ + "\":" + std::to_string(value) + "\n" + "}";
    return v;
}
