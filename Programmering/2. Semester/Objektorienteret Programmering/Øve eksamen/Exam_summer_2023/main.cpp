#include "Matrix2.h"



int main (){
    Matrix2 m1 (2.3, 5.6, 6.7, 6.9);
    Matrix2 m2 (2.1, 4.6, 3.7, 9.9);

    std::cout << m1 << std::endl;
    std::cout << m2 << std::endl;

    Matrix2 m3 = m1 + m2;
    
    std::cout << m3 << std::endl;
}