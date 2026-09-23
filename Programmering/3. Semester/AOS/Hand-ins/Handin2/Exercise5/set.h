#include <iostream>
#include "linked_list.h"



template <typename Object>
class Set{
    private:
        Linkedlist<Object> list;

    public:
        void insert(const Object x);
        bool contains(const Object x);
        void remove(const Object x);        
};

template <typename Object>
bool Set<Object>::contains(const Object x){
    try {
        list.find(x);
        return true;
    } catch (const std::out_of_range&) {
        return false;
    }
}

template <typename Object>
void Set<Object>::insert(const Object x){
    if(contains(x) == false){
        list.push_back(x);
    }
}

template <typename Object>
void Set<Object>::remove(const Object x){
    Linkedlist<Object> temp;
    
    while(!list.empty()){
        Object val = list.pop_front();
        if(val == x){
            continue;
        }
        else{
            temp.push_back(val);
        }
    }

    while(!temp.empty()){
        Object val = temp.pop_front();
        list.push_back(val);
    }
}
