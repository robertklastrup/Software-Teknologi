#pragma once

#include <vector>
#include "box.h"

class boxes {
public:
    void add_box(const box &);

private:
    std::vector<box> boxes_;
};