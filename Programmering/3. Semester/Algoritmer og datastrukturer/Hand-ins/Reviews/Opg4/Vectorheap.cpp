#include "Maxheap.h"
#include <stdexcept>

bool Maxheap::isEmpty() const {
    return heap.empty();
}

int Maxheap::size() {
    return heap.size();
}

void Maxheap::insert(const int x) {
    heap.emplace_back(x);
}

const int Maxheap::findMax() const {
    if(isEmpty()) {
        throw std::runtime_error("Empty heap")
    }

    auto it = heap.begin();
    int MAX = *it;

    for(; it != heap.end(); ++it) {
        if(*it > MAX) {
            MAX = *it;
        }
    }
    return MAX;
}

int Maxheap::deleteMax() {
    int MAX = findMax();
    auto it = find(heap.begin(), heap.end(), MAX);
    heap.erase(it);
    return MAX;
}