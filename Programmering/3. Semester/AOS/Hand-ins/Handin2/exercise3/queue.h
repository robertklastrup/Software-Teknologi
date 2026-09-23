#pragma once
#include <iostream>

#include "stack.h"


template <typename Object>
class Queue{
    private:
        Stack<Object> inStack;
        Stack<Object> outStack;
    public:
        bool empty();
        Object front();
        Object get();
        void put(const Object x);
};

template <typename Object>
bool Queue<Object>::empty(){
    if(inStack.empty() == true && outStack.empty() == true){
        return true;
    }
    else{
        return false;
    }
}

template <typename Object>
Object Queue<Object>::front(){
    if(outStack.empty() == true){
        while(!inStack.empty()){
            outStack.push(inStack.pop());
        }
    }
    return outStack.top();
}

template <typename Object>
Object Queue<Object>::get(){
    if(outStack.empty() == true){
        while(!inStack.empty()){
            outStack.push(inStack.pop());
        }
    }
    return outStack.pop();
}

template <typename Object>
void Queue<Object>::put(const Object x){
    inStack.push(x);
}