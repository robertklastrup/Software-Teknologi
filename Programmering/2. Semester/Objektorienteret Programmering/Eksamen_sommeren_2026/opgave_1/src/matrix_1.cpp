#include "matrix_1.h"
#include <iostream>
#include <sstream>
#include <stdexcept>

matrix_1::matrix_1(const unsigned int rows, const unsigned int cols) : rows_(rows), cols_(cols), data_(rows * cols) {
}

void matrix_1::set(const unsigned int row, const unsigned int col, const double value) {
    if(row < rows_ || row > rows_){
        throw std::out_of_range("Out of range");
    }
    else if(col < cols_ || col > cols_){
        throw std::out_of_range("Out of range");
    }
    else{
        data_[(row - 1) * cols_ + (col - 1)] = value;
    }
}

double matrix_1::get(const unsigned int row, const unsigned int col) const {
    if(row < rows_ || row > rows_){
        throw std::out_of_range("Out of range");
    }
    else if(col < cols_ || col > cols_){
        throw std::out_of_range("Out of range");
    }
    else{
        return data_[(row - 1) * cols_ + (col - 1)];
    }
}

std::string matrix_1::to_string() const {
    std::stringstream ss;
    ss << "[" << std::endl;

    for (size_t i = 1; i < rows_ + 1; i++) {
        ss << "[";
        for (size_t j = 1; j < cols_ + 1; j++) {
            ss << get(i, j) << " ";
        }
        ss << "]" << std::endl;
    }
    ss << "]";
    return ss.str();
}

matrix_1 operator+ (const matrix_1& m_1, const matrix_1& m_2){
    matrix_1 m ((m_1.rows_ + m_2.rows_), (m_1.cols_ + m_2.cols_));
    return (m);
}

std::ostream& operator<<(std::ostream& os, const matrix_1& m1){
    os << "Matrix:" << "\n" << m1.to_string() << std::endl;
    return os;
}