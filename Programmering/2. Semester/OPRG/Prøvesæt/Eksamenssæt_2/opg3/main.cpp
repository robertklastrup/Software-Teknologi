#include "opg3.h"



int main (){
    Car c1 ("Toyota", 50, 0);
    if (c1.isValid() == false){
        std::cout << c1.makeValid() << std::endl;
    }
    else{
        c1.print();
    }
}