#include "Zoo.h"


void Zoo::add(Animal* a){
    animals_.push_back(a);
}

std::string Zoo::describe_all() const{
    std::string describe;
    for (int i = 0; i < animals_.size(); i++){
        describe = describe + " " + animals_[i]->describe() + "\n";
    }
    return describe;
}
int Zoo::count() const{
    int x = animals_.size();
    return x;
}