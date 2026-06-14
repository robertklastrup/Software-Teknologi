#pragma once

#include "ascii_art.h"
#include <vector>

class ascii_text {
public:
    void add(ascii_art *);

private:
    std::vector<ascii_art *> arts_;
};