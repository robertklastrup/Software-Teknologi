#pragma once

class MaxHeap {
    public:
        //checks if heap is empty
        virtual bool isEmpty() const = 0;

        //returns number of elements in the heap
        virtual int size() = 0;

        //adds an element to the heap
        virtual void insert(const int x) = 0;
        
        //finds the maximum element in the heap
        virtual const int findMax() const = 0;
        
        //deletes and returns the maximum element in the heap
        virtual int deleteMax() = 0;
};