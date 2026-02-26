
#include <iostream>
#include "Kontraharmonisk.h"

using namespace std;

int main()
{
    double a = 4.0;
    double b = 2.0;

    cout << "a = " << a << ", b = " << b << endl;
    cout << "Kontraharmonisk middel: "
         << kontraharmoniskMiddel(a, b) << endl;

    return 0;
    
}


