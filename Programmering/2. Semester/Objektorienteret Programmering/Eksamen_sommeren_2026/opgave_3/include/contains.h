#pragma once
#include <algorithm>
#include <numeric>


template <typename C, typename E>
bool contains(const C &container, const E &element) {
    auto it = container.begin();
    while (it != container.end()) {
    if (*it == element) {
        return true; // erase returnerer næste iterator
    } else {
        return false;
        ++it;
    }
    }
    
}
