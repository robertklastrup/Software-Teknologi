#include "opg5.h"

int main (){
    Car c1("Toyota", 120, Volumen(50, Liter));
    Car c2("BMW", 200, Volumen(30, Liter));
    Car c3 ("Mercedes", 240, Volumen(40, Gallon));

    std::cout << gennemsnit({c1, c2, c3}, Volumen(2,Gallon)) << std::endl;
}