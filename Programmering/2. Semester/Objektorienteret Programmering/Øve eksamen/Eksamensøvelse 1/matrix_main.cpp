#include "Matrix2.h"



int main(){
    Matrix2 m1 (2.1, 3.5, 5.1, 5.5);
    Matrix2 m2 (2.1, 3.5, 5.1, 5.5);

    std::cout << "Matricer:" << std::endl;
    std::cout << "Matrix 1:" << '\n' << m1 << std::endl;
    std::cout << "Matrix 2:" << '\n' << m2 << std::endl;
    std::cout << std::endl;
    std::cout << "Matricerne ganget sammen:" << std::endl;

    Matrix2 m3 = m1 * m2;
    std::cout << m3 << std::endl;
}