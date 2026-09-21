#include <iostream>
#include "queue.h"


int main(){
    Queue<int> q;
    q.put(1);
    q.put(2);
    q.put(3);
    std::cout << q.get() << std::endl;  // expected: 1
    std::cout << q.get() << std::endl;  // expected: 2
    q.put(4);
    std::cout << q.get() << std::endl;  // expected: 3
    std::cout << q.get() << std::endl;  // expected: 4
}