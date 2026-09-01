#include <iostream>
#include "int_array.h"

int main() {
    int_array array{2, 2};
    array.push_back(10);
    array.push_back(9);
    std::cout << array.to_string() << "\n";
    array.push_back(8);
    array.push_back(7);
    std::cout << array.to_string() << "\n";
}