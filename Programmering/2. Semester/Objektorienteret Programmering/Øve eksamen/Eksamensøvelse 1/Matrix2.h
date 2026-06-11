#pragma once
#include <iostream>



class Matrix2{
    private:
        double k11;
        double k12;
        double k21;
        double k22;
    public:
        Matrix2(
            double k11 = 1, double k12 = 0,
            double k21 = 0, double k22 = 1);
            friend std::ostream& operator<<(std::ostream& os, const Matrix2& k);
            friend Matrix2 operator*(const Matrix2& m1, const Matrix2& m2);

};