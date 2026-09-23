#include <iostream>
#include "linked_list.h"
#include <string>
#include <stdexcept>

int main() {
    Linkedlist<int> lst;

    std::cout << "Test empty list\n";
    std::cout << "Empty? " << (lst.empty() ? "yes" : "no") << "\n";
    std::cout << "Size: " << lst.size() << "\n";

    std::cout << "\nTest push_front\n";
    lst.push_front(20);
    lst.push_front(10);
    lst.print(); // expected: h-> [10]->[20]->tail

    std::cout << "\nTest push_back\n";
    lst.push_back(30);
    lst.push_back(40);
    lst.print(); // expected: h-> [10]->[20]->[30]->[40]->tail

    std::cout << "\nTest push_middle\n";
    lst.push_middle(2, 99); // insert at position 2
    lst.print(); // expected: h-> [10]->[20]->[99]->[30]->[40]->tail

    std::cout << "\nSize: " << lst.size() << "\n";

    std::cout << "\nTest find\n";
    std::cout << "Found: " << lst.find(99) << " (expected 99)\n";

    std::cout << "\nTest pop_front\n";
    std::cout << "Popped: " << lst.pop_front() << " (expected 10)\n";
    lst.print();

    std::cout << "\nTest pop_back\n";
    std::cout << "Popped: " << lst.pop_back() << " (expected 40)\n";
    lst.print();

    std::cout << "\nTest pop_middle\n";
    // current list: [20]->[99]->[30]
    std::cout << "Popped at pos 1: " << lst.pop_middle(1) << " (expected 99)\n";
    lst.print(); // expected: h-> [20]->[30]->tail

    std::cout << "\nTest reverse\n";
    lst.push_back(40);
    lst.push_back(50);
    lst.print(); // h-> [20]->[30]->[40]->[50]->tail
    lst.reverse();
    lst.print(); // expected: h-> [60]->[50]->[40]->[30]->tail

    std::cout << "\nTest clear\n";
    lst.clear();
    try{ lst.print(); }
    catch(const std::exception& e){ std::cerr << e.what(); }

    std::cout << "Size: " << lst.size() << "\n";
    
    return 0;
}




/*
As seen in the output of the terminal the different functions has been tested. 
The push_front / push_back / push_middle, and pop_front / pop_back / pop_middle.
The print, empty and size function all works as intended, as do the rest of the functions with he linked list.


*/