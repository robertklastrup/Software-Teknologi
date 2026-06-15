#include <iostream>

#include "Tests.h"

int main()
{
    std::cout << "Begin test of question b-2" << "\n";
    test_to_string();
    std::cout << "Check Success test of question b-2" << "\n";
    std::cout << "\n \n";


    std::cout << "Begin test of question c-2" << "\n";
    test_additive_inverse_operator();
    std::cout << "Check Success test of question c-2" << "\n";
    std::cout << "\n \n";


    std::cout << "Begin test of question d-3" << "\n";
    test_addition_operator();
    std::cout << "Check Success test of question d-3" << "\n";
    std::cout << "\n \n";


    std::cout << "Begin test of question e-3" << "\n";
    test_subtraction_operator();
    std::cout << "Check Success test of question e-3" << "\n";
    std::cout << "\n \n";

    return 0;
}
