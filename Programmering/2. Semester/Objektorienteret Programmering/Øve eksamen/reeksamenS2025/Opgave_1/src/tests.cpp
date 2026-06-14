#include "tests.h"
#include "box.h"
#include "boxes.h"
#include <cassert>
#include <iostream>
#include <ostream>
#include <algorithm>

// Pre-implemented test of volume
void test_box_volume() {
    box b{1.4, 2.3, 3.9};
    // you can use asserts as test-tool,
    // but it is not required! assert simply takes a bool expression as input and fails if it is false
    // and is in include-file <cassert>
    assert(std::abs(b.volume() - 12.558) < box::delta);
}

void test_box_equals_operator() {
    box b_1(3, 4, 5);
    box b_2(3, 4, 5);

    if (b_1 == b_2)
    {
        std::cout << "b_1 == b_2" << std::endl;
    }
    else
    {
        std::cout << "b_1 != b_2" << std::endl;
    }
}

void test_box_less_than_operator() {
    box b_1(3, 6, 5);
    box b_2(3, 4, 5);

    if (b_1 < b_2)
    {
        std::cout << "b_1 < b_2" << std::endl;
    }
    else
    {
        std::cout << "b_1 !< b_2" << std::endl;
    }
    if (b_2 < b_1)
    {
        std::cout << "b_2 < b_1" << std::endl;
    }
    else
    {
        std::cout << "b_2 !< b_1" << std::endl;
    }
}

void test_boxes_to_string() {
    boxes bs;
    box b_1(3, 6, 5);
    box b_2(3, 4, 5);
    box b_3(5, 8, 9);

    bs.add_box(b_1);
    bs.add_box(b_2);
    bs.add_box(b_3);

    std::cout << bs.to_string();

}

void test_boxes_to_string_sorted() {
    boxes bs;
    box b_1(3, 6, 5);
    box b_2(3, 4, 5);
    box b_3(5, 8, 9);

    bs.add_box(b_1);
    bs.add_box(b_2);
    bs.add_box(b_3);

    std::cout << bs.to_string_sorted() << std::endl;
    std::cout << bs.to_string();
}
