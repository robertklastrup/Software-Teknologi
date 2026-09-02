#include "opg4.h"


int main (){
    Order o1(2, 704.4, "LEVERET");
    Order o2(3, 505.8, "PAKKET");
    Order o3(2, 550.5, "AFSENDT");
    Order o4(3, 1257.9, "LEVERET");

    o1.isValid();
    o2.isValid();
    o3.isValid();
    o4.isValid();

    o1.makeValid();
    o2.makeValid();
    o3.makeValid();
    o4.makeValid();
    std::cout << gennemsnit({o1,o2,o3,o4}, 2) << std::endl;
    std::cout << gennemsnit({o1,o2,o3,o4}, 3) << std::endl;

    //verificering:
    std::cout << "Verificering:" << std::endl;
    std::cout << ((704.4 + 550.5)/2) << std::endl;
    std::cout << ((505.8 + 1257.9)/2) << std::endl;


}