#include "prng.h"
#include <random>

int prng() {
    std::random_device rd;                          // O(1) 
    std::mt19937 gen(rd());                         // O(1)
    std::uniform_int_distribution<> dist(0,100);    // O(1)

    int m = dist(gen);                              // O(1)

    return m;
}