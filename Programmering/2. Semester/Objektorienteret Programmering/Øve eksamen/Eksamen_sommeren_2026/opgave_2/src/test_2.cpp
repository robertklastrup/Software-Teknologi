#include "test_2.h"
#include "matrix_2.h"
#include <iostream>

void test_matrix() {
    matrix_2 m(4, 2);
    m.set(1, 1, 1);
    m.set(1, 2, 1);
    m.set(2, 1, 1);
    m.set(2, 2, 2);
    m.set(3, 1, 8);
    m.set(3, 2, 9);
    m.set(4, 1, 11);
    m.set(4, 2, 12);
    std::cout << m.to_string() << "\n\n";
}
