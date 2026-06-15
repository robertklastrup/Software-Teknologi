#include <vector>
#include "Animal.h"

class Zoo{
    private:
        std::vector<Animal*> animals_;
    public:
        void add(Animal* a);
        std::string describe_all() const;
        int count() const;
};