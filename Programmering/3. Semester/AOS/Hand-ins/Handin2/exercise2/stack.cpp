#include "stack.h"

Stack::Stack(): arr(new int[100]), capacity(100), top(-1) {}

Stack::Stack(int s): arr(new int[s]), capacity(s), top(-1) {}

void Stack::push(int value){
    if(top == capacity-1){
        int newCapacity = capacity*2;
        int* NewArray = new int[newCapacity];

        
        for(int i = 0; i<=top; i++){
            NewArray[i] =  arr[i];
        }
        delete[] arr;
        arr = NewArray;
        capacity = newCapacity;

    }
    arr[++top] = value;
}

int Stack::pop(){
    return arr[top--];
}

Stack::~Stack() {
    delete[] arr;
}

int Stack::getCapacity(){
    return capacity;
}