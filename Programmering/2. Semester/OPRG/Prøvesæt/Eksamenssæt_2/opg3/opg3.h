#include <iostream>


/*
Implementér en UML-klasse Car med attributter: brand (string), speed (double), fuel (double).
Krav: constructor initialiserer alle attributter. 
Objektet er gyldig hvis speed>=0 og fuel>=0. 
Hvis fuel=0 skal speed også være lig 0. 
Implementér en metode - isValid() – som checker om objektet er gyldigt.
Lav derudover en metode – makeValid() – som benytter isValid() til at checke om objektet er gyldigt.
Hvis det ikke er det, sættes både fuel og speed til 0. Hvilken returtype skal de to metoder have? 
*/

class Car{
    private:
        std::string brand;
        double speed;
        double fuel;
    public:
        Car(std::string b, double s, double f);
        void print ();
        bool isValid();
        bool makeValid();
};