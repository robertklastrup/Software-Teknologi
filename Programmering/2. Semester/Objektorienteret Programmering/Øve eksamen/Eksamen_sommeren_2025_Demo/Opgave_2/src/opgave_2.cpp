#include <iostream>
#include "Tests.h"

int main()
{
    std::cout << "This is the start of already implemented test of the time series class" << "\n";
    test_series();
    std::cout << "This is the end of already implemented test of the time series class" << "\n";
    std::cout << "\n \n";

    std::cout << "Begin test of question b" << "\n";
    test_series_template_double();
    std::cout << "\n";
    std::cout << "Check Success test of question b" << "\n";
    std::cout << "\n \n";


    std::cout << "Begin test of question c" << "\n";
    test_series_template_vector();
    std::cout << "\n";
    std::cout << "Check Success test of question c" << "\n";
    std::cout << "\n \n";

    return 0;
}
