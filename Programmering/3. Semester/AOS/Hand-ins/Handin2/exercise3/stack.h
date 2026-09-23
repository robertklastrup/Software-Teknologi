#pragma once

template <typename Object>
class Stack{
private:
    Object* arr;
    int capacity;
    int topIndex;

public:
    Stack(): arr(new Object[100]), capacity(100), topIndex(-1) {}
    Stack(int s): arr(new Object[s]), capacity(s), topIndex(-1) {}
    
    int getCapacity(){
        return capacity;
    }

    void push(const Object x){
        if(topIndex == capacity-1){
            int newCapacity = capacity*2;
            Object* NewArray = new Object[newCapacity];   

            for(int i = 0; i <= topIndex; i++){
                NewArray[i] = arr[i];
            }
            delete[] arr;
            arr = NewArray;
            capacity = newCapacity;
        }
        arr[++topIndex] = x;
    }


    Object pop(){        
        return arr[topIndex--];
    }

    Object top(){
        return arr[topIndex];
    }

    bool empty(){     
        return topIndex == -1;
    }

    ~Stack(){
        delete[] arr;
    }

};
