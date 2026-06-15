#pragma once
#include "Transformer.h"



class translation : public transformer{
    private:
        double dx;
        double dy;
    public:
        translation(double dx, double dy);
        point transform(const point& p);
};