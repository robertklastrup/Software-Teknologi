#pragma  once
#include <vector>
#include <iostream>
#include "string_writer.h"
template <typename Iterator>
std::string as_string(Iterator begin, Iterator end);

template <typename Iterator>
std::string as_string(Iterator begin, Iterator end) {
    bool first = true;
    std::ostringstream os;
    for (auto it = begin; it != end; ++it) {
        if (!first) {
            os << ", ";
        }
        os << *it;
        first = false;
    }
    return os.str();
}