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
        double getK11();
        double getK12();
        double getK21();
        double getK22();
        friend std::ostream& operator<<(std::ostream& os, const Matrix2& m1);
        friend Matrix2 operator+(Matrix2& m1, Matrix2& m2);
};

