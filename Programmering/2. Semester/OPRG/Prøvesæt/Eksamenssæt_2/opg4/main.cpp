#include "opg4.h"


int main (){
    Car c1("Toyota", 120, 50);
    Car c2("BMW", 200, 30);
    Car c3 ("Mercedes", 240, 40);

    std::cout << gennemsnit({c1, c2, c3}, 35) << std::endl;
}