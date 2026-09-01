#include "opg3.h"


int main(){
    Ansat a1 ("Jens", 50000, -5, "Software");
    Ansat a2 ("Jens", -5000, 4, "Software");
    Ansat a3 ("Jens", -5000, -4, "Software");

    a1.isValid();
    a1.makeValid();

    a2.isValid();
    a2.makeValid();

    a3.isValid();
    a3.makeValid();

    a1.print();
    a2.print();
    a3.print();
}