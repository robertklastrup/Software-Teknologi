#include <iostream>
#include "prng.h"
#include <vector>
#include <algorithm>

int main() {
    int m = 0;                                                                                          // O(1)
    int n = 0;                                                                                          // O(1)
    int counter = 0;                                                                                    // O(1)

    std::cout << "Input the M amount: ";                                                                // O(1)
    std::cin >> m;                                                                                      // O(1)

    std::cout << "Input the N amount: ";                                                                // O(1)
    std::cin >> n;                                                                                      // O(1)

    std::vector<int> mvector;                                                                           // O(1)
    
    while (m > 0) {                                                                                     // O(m)
        mvector.push_back(prng());                                                                      // O(1) am
        --m;                                                                                            // O(1)
    }                                                                                                   // loop: O(m)

    while (n > 0) {                                                                                     // O(n)
        int number = prng();                                                                            // O(1)
        
        auto result = std::find(mvector.begin(), mvector.end(), number);                                // O(m)
        if (result != mvector.end()) {                                                                  // O(1)
            ++counter;                                                                                  // O(1)
        }
        --n;                                                                                            // O(1)
    }                                                                                                   // loop: O(n*m)
    for (auto i : mvector) {                                                                            // O(m)
        std::cout << i << " ";                                                                          // O(1)
    }                                                                                                   // loop: O(m)

    std::cout << std::endl;                                                                             // O(1)
    
    std::cout << "N intergers was found " << counter << " amount of times in the array" << std::endl;   // O(1)

    return 0;
}