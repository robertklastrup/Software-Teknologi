#include <iostream>

#include "Tests.h"

int main()
{
    std::cout << "Begin test of question c-2" << "\n";
    test_rotation();
    std::cout << "Check Success test of question c-2" << "\n";
    std::cout << "\n";

    std::cout << "Begin test of question e-2" << "\n";
    test_translation();
    std::cout << "Check Success test of question e-2" << "\n";
    std::cout << "\n";

    std::cout << "Begin test of question g-2" << "\n";
    test_combiner();
    std::cout << "Check Success test of question g-2" << "\n";
    std::cout << "\n";

}
