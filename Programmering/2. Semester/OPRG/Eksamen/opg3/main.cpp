#include "opg3.h"


int main(){
    Order o1(-1, -500, "XYZ");
    Order o2(1234, -500, "PAKKET");
    Order o3(1234, 500, "XYZ");
    Order o4(-1, 500, "LEVERET");

    std::cout << "Før makeValid()" << std::endl;
    o1.print();
    o2.print();
    o3.print();
    o4.print();

    std::cout << std::endl;

    /*o1.isValid();
    o2.isValid();
    o3.isValid();
    o4.isValid();

    o1.makeValid();
    o2.makeValid();
    o3.makeValid();
    o4.makeValid();

    std::cout << "Efter makeValid()" << std::endl;
    o1.print();
    o2.print();
    o3.print();
    o4.print();*/

}