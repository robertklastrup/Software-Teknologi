#include "test_point.h"

void test_point_streaming_operator() {
    point p (3,4);
    std::cout << p << std::endl;
}

void test_point_subtraction_operator() {
    point p1 (3,4);
    point p2 (6,7);

    point p3 = p1-p2;
    std::cout << p3 << std::endl;
}

void test_point_norm() {
    point p (3,4);
    std::cout << p.norm() << std::endl;
}






