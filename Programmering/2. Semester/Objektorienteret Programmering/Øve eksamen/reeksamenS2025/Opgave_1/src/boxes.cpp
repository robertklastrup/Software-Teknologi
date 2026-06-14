#include "boxes.h"

void boxes::add_box(const box &b) {
    boxes_.emplace_back(b);
}