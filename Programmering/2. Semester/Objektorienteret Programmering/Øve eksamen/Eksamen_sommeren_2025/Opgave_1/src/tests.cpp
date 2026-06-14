#include "point.h"
#include "square.h"
#include <iostream>


void test_point_add() {
    point p_1 (2,3);
    point p_2 (8,7);

    point p_3 = p_1 + p_2;
    std::cout << "(" << p_3.x << "," << p_3.y << ")" << std::endl;
}

void test_point_stream() {
    point p (1,2);
    std::cout << p << std::endl;
}

void test_square_add() {
    square s1 (point (1,2), 10);
    square s2 (point (4,5), 15);

    square s3 = s1 + s2;

    std::cout << s3.get_center() << " " << s3.area() << std::endl;

}

void test_square_stream() {
    square s (point (1,2), 16);
    std::cout << s << std::endl;
}