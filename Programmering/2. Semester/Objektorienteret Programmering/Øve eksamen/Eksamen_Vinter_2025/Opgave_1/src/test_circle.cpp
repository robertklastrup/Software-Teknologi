#include "test_circle.h"

void test_circle_streaming_operator() {
    std::cout << "test_circle_streaming_operator" << "\n";
    circle c(point(1, 2), 4);
    std::cout << c;
}

void test_circle_scale_operator() {
    circle c(point(1, 2), 4);
    std::cout << c << std::endl;
    circle c2 = c * 5;
    std::cout << c2;
}

void test_circle_intersect_operator() {
    circle A (point(3, 4), 2);
    circle B (point(1, 2), 1);
    circle C (point(0, 0), 1);

    if (A && B)
    {
        std::cout << "A og B overlapper" << "\n";
    }
    else
    {
        std::cout << "A og B overlapper ikke" << "\n";
    }
    if (C && B)
    {
        std::cout << "C og B overlapper" << "\n";
    }
    else
    {
        std::cout << "C og B overlapper ikke" << "\n";
    }
}
