#include "Combiner.h"
// Opgave g-1)

void combiner::add (transformer* t){
    transformers.push_back(t);
}


point combiner::transform(const point& p){
    point p1 = p;
    for (int i = 0; i < transformers.size(); i++){
        p1 = transformers[i]->transform(p1);
    }
    return p1;
}