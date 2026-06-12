#include "sum.h"


template<typename T>
T sum(typename std::vector<T>::iterator begin, typename std::vector<T>::iterator end, T initial_sum){
    while (begin != end){
        initial_sum = initial_sum + *begin;
        begin++;
    }
    return (initial_sum);
}
