#include "opg2.h"

double volumen (double radius){
    double r = radius;
    
    double volume = (3.00/4.00) * 3.14 * (r * r * r);

    return volume;
}

void print (){
    int start; 
    int slut;
    std::cout << "Skriv dit start tal" << std::endl;
    std::cin >> start;
    std::cout << "Skriv dit slut tal" << std::endl;
    std::cin >> slut;


    for (int i = start; i <= slut; i++){
        std::cout << "Volumen med en radius på: " << i << ": "<< volumen (i) << std::endl;
    }
}