#include "FakturaLinje.h"
#include "Vare.h"
#include "Service.h"
#include <vector>


int main (){
    
    FakturaLinje* f1 = new Vare("Stolpe", 160.00, 2);
    FakturaLinje* f2 = new Service("Stol",319.99, 6, true);
    FakturaLinje* f3 = new Vare("Vand", 12.00, 48);
    FakturaLinje* f4 = new Service("Lampe",250, 6, true);

    std::vector<FakturaLinje*> fakturaer = {f1, f2, f3, f4};

    auto it = fakturaer.begin();
    while( it!=fakturaer.end()){
        (*it)->print();
        ++it;
    }

    delete f1;
    delete f2;
    delete f3;
    delete f4;
}