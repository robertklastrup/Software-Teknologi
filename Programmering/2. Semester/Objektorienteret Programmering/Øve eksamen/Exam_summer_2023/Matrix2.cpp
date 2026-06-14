#include "Matrix2.h"



Matrix2::Matrix2(double k11, double k12, double k21, double k22)
{
    this->k11 = k11;
    this->k12 = k12;
    this->k21 = k21;
    this->k22 = k22;
}

double Matrix2::getK11(){
    return k11;
}
double Matrix2::getK12(){
    return k12;
}
double Matrix2::getK21(){
    return k21;
}
double Matrix2::getK22(){
    return k22;
}

std::ostream& operator<<(std::ostream& os, const Matrix2& m1){
    os << "[[" << m1.k11 << ", " << m1.k12 << "], [" << m1.k21 << ", " << m1.k22 << "]]" << std::endl;
    return os;
}

Matrix2 operator+(Matrix2& m1, Matrix2& m2){
    return (
        (m1.k11 * m2.k11 + m1.k12 * m2.k21), (m1.k11 * m2.k12 + m1.k12 * m2.k22),
        (m1.k21 * m2.k11 + m1.k22 * m2.k21), (m1.k21 * m2.k12 + m1.k22 * m2.k22)
    );
}