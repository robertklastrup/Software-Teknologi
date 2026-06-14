#include "csv_unique_sorted_collector.h"

csv_unique_sorted_collector::csv_unique_sorted_collector(double upper_limit) : upper_limit_(upper_limit) {}

bool csv_unique_sorted_collector::filter(double value) const{
    if (value <= upper_limit_){
        return true;
    }
    else{
        return false;
    }
}

std::string csv_unique_sorted_collector::format(double value) const{
    std::string v = std::to_string(value) + ", ";
    return v;
}