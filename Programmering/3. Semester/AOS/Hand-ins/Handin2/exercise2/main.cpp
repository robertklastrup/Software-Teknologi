#include <iostream>
#include "stack.h"

int main() {
    Stack<int> s(2); // small capacity to trigger resize
    std:: cout << "Capacity of stack: " << s.getCapacity() << "\n";
    s.push(1);
    s.push(2);
    s.push(3); // triggers resize (capacity 2 -> 4)
    std:: cout << "Capacity of stack after resize: " << s.getCapacity() << "\n";
    s.push(4);

    std::cout << "Pop: " << s.pop() << " (expected 4)\n";
    std::cout << "Pop: " << s.pop() << " (expected 3)\n";
    std::cout << "Pop: " << s.pop() << " (expected 2)\n";
    std::cout << "Pop: " << s.pop() << " (expected 1)\n";

    return 0;
}

/*
Fairly short task, but the main shows clearly our array works as a stack. 
The resize function works as intended, it clearly resize with size()*2.
The variable top is basicaly an index which is used to locate the top element so when we pop an element: return arr[top--] 
it uses the value of top, and returns that as an integer. Then we decrement the top value and we have poped the top element.
*/