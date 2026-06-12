#include "niveau1.h"


void Dyr::print (){
    std::cout << "Navn: " << navn << std::endl;
    std::cout << "Alder: " << alder << std::endl;

}



void Hund::print(){
    Dyr::print();
    std::cout << "Race: " << race << std::endl;
}
