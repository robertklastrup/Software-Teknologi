#include <iostream>
#include "set.h"



int main(){
    Set<int> s;

    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(2);   // dublet: bør ikke ændre noget

    std::cout << "contains(1): " << s.contains(1) << " (expected 1)\n";
    std::cout << "contains(2): " << s.contains(2) << " (expected 1)\n";
    std::cout << "contains(3): " << s.contains(3) << " (expected 1)\n";
    std::cout << "contains(4): " << s.contains(4) << " (expected 0)\n";

    s.remove(2);
    std::cout << "\nAfter remove(2):\n";
    std::cout << "contains(1): " << s.contains(1) << " (expected 1)\n";
    std::cout << "contains(2): " << s.contains(2) << " (expected 0)\n";
    std::cout << "contains(3): " << s.contains(3) << " (expected 1)\n";

    s.remove(99);  // Doesn't exist, shouldn't crash or change anythin
    std::cout << "\nAfter remove(99) (doesn't exist):\n";
    std::cout << "contains(1): " << s.contains(1) << " (expected 1)\n";
    std::cout << "contains(3): " << s.contains(3) << " (expected 1)\n";
}
