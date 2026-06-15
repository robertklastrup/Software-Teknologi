#pragma once
#include "Transformer.h"
#include <vector>
//Opgave f)

class combiner : public transformer{
    private:
        std::vector<transformer*> transformers;
    public:
        void add (transformer* t);
        point transform(const point& p);
};