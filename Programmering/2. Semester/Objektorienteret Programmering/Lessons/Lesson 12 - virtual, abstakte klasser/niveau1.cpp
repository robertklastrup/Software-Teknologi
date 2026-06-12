#include "niveau1.h"

void Form::print(){
    std::cout << farve << std::endl;
}

double Cirkel::areal(){
    return (3.14 * radius * radius);
}

void Cirkel::print (){
    Form::print();
    std::cout << radius << std::endl;
    std::cout << areal() << std::endl;
}

double Rektangel::areal(){
    return (hoejde * bredde);
}

void Rektangel::print(){
    Form::print();
    std::cout << bredde << std::endl;
    std::cout << hoejde << std::endl;
    std::cout << areal() << std::endl;
}
