#include "test_1.h"
#include <iostream>
#include "matrix_1.h"

void test_to_string() {
    matrix_1 m(4, 2);
    m.set(1, 1, 1);
    m.set(1, 2, 1);
    m.set(2, 1, 1);
    m.set(2, 2, 2);
    m.set(3, 1, 8);
    m.set(3, 2, 9);
    m.set(4, 1, 11);
    m.set(4, 2, 12);
    std::cout << m.to_string() << "\n\n";
}


void test_add() {
    matrix_1 m1 (3,4);
    matrix_1 m2 (5,4);
    matrix_1 m3 = m1 + m2;

    std::cout << m3.to_string();
}

void test_stream() {
    matrix_1 m1 (3,4);
    std::cout << m1;
}

void test_exception() {
    
    try{
        matrix_1 m1 (3,4);
        m1.get(4,1);
    }catch (std::out_of_range& e){
        std::cout << "Exception caught"  << e.what()<< std::endl;
    }
    
    try{
        matrix_1 m1 (3,4);
        m1.get(2,5);
    } catch (std::out_of_range& e){
        std::cout << "Exception caught" << e.what() << std::endl;
    }
    
    
}
