#include "FakturaLinje.h"
#include "Service.h"
#include "Vare.h"




int main (){
    FakturaLinje* f1 = new Vare("Stolpe", 160.00, 2);
    FakturaLinje* f2 = new Service("Stol",319.99, 6, true);

    f1->print();
    f2->print();
}