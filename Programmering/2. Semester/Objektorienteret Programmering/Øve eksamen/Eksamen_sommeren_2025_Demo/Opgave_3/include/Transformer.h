#pragma once
#include "Point.h"
// Opgave a)

class transformer {
    public:
        virtual point transform(const point& p) = 0;
};