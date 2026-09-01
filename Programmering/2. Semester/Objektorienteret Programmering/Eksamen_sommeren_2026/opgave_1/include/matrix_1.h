#pragma once
#include <vector>
#include <string>

class matrix_1 {
public:
    matrix_1(unsigned int rows, unsigned int cols);

    void set(unsigned int, unsigned int, double);

    double get(unsigned int, unsigned int) const;


    std::string to_string() const;
    friend matrix_1 operator+ (const matrix_1&, const matrix_1&);
    

private:
    unsigned int rows_;
    unsigned int cols_;
    std::vector<double> data_;
};

std::ostream& operator<<(std::ostream& os, const matrix_1& m1);