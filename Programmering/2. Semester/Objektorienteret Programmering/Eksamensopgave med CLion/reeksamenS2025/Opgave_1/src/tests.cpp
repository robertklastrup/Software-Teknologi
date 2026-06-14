#include "tests.h"
#include "box.h"
#include <cassert>

// Pre-implemented test of volume
void test_box_volume() {
    box b{1.4, 2.3, 3.9};
    // you can use asserts as test-tool,
    // but it is not required! assert simply takes a bool expression as input and fails if it is false
    // and is in include-file <cassert>
    assert(std::abs(b.volume() - 12.558) < box::delta);
}

void test_box_equals_operator() {

}

void test_box_less_than_operator() {

}

void test_boxes_to_string() {

}

void test_boxes_to_string_sorted() {

}
