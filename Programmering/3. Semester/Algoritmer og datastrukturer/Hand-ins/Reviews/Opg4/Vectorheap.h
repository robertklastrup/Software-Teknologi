#include "Maxheap.h"
#include <vector>

class Vectorheap : public MaxHeap {
    public:
        bool isEmpty() const override;
        int size() override;
        void insert(const int x) override;
        const int findMax() const override;
        int deleteMax() override;

    private:
        std::vector<int> heap;
};