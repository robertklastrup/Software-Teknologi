#include "unique_sorted_collector.h"

void unique_sorted_collector::collect(double value){
    data_.insert (value);
}


std::vector <double> unique_sorted_collector::prepare()const{
    std::vector <double> result (data_.begin(), data_.end());
    return (result);
}