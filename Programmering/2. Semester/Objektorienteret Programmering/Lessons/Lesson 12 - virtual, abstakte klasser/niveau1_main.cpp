#include "niveau1.h"


int main (){
    Form* f1 = new Cirkel("Rød", 5.0);
    Form* f2 = new Rektangel("Blå", 4.0, 6.0);

    f1->print();
    f2->print();

    std::cout << f1->areal() << std::endl;
    std::cout << f2->areal() << std::endl;

    delete f1;
    delete f2;
}