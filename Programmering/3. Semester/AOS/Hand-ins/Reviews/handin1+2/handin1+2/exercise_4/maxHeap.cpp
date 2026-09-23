#include "maxHeap.h"
#include "iostream"
class MaxHeapClass : public MaxHeap
{
private:
    std::vector<int> numbers;

public:
    bool isEmpty() const 
    {
        for (auto it = numbers.begin(); it != numbers.end(); it++)
        {
            if (numbers.empty())
            {
                return true;
            }
            return false;
        }
    }

    int size()
    { 
        return numbers.size();
    }

    void insert(const int x)
    { 
        numbers.push_back(x);
    }

    const int findMax() const
    { 
        auto maxIt = numbers.begin();

        for (auto it = numbers.begin(); it != numbers.end(); it++)
        {
            if (*it > *maxIt)
            {
                maxIt = it;
            }
        }
        return *maxIt;
    }

    int deleteMax()
    { 
        auto maxIt = numbers.begin();

        for (auto it = numbers.begin(); it != numbers.end(); it++)
        {
            if (*it > *maxIt)
            {
                maxIt = it;
            }
        }
        int temporaryMax = *maxIt;
        numbers.erase(maxIt);

        return temporaryMax;
    }
};

int main()
{
    MaxHeapClass m1;

    m1.insert(10);
    m1.insert(5);
    m1.insert(20);
    m1.insert(40);

    std::cout << m1.findMax() << std::endl;
    std::cout << m1.isEmpty() << std::endl;
}