#pragma once

template <typename Object>
class Stack{
private:
    Object* arr;
    int capacity;
    int topIndex;

public:
    Stack();
    Stack(int s);
    int getCapacity();
    void push(const Object x);
    Object pop();
    Object top();
    bool empty();
    ~Stack();
};

template <typename Object>
Stack<Object>::Stack(): arr(new Object[100]), capacity(100), topIndex(-1) {}

template <typename Object>
Stack<Object>::Stack(int s): arr(new Object[s]), capacity(s), topIndex(-1) {}

template <typename Object>
void Stack<Object>::push(const Object x){
    if(topIndex == capacity-1){
        int newCapacity = capacity*2;
        Object* NewArray = new Object[newCapacity];   // var int*, skal være Object*

        for(int i = 0; i <= topIndex; i++){
            NewArray[i] = arr[i];
        }
        delete[] arr;
        arr = NewArray;
        capacity = newCapacity;
    }
    arr[++topIndex] = x;
}


template <typename Object>
Object Stack<Object>::pop(){        
    return arr[topIndex--];
}
template <typename Object>
Object Stack<Object>::top(){        
    return arr[topIndex];
}

template <typename Object>
int Stack<Object>::getCapacity(){
    return capacity;
}

template <typename Object>
bool Stack<Object>::empty(){        
    return topIndex == -1;
}

template <typename Object>
Stack<Object>::~Stack() {
    delete[] arr;
}