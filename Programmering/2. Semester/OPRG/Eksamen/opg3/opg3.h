#include <iostream>

/*
Implementér en klasse Order med attributter: id (int), amount (double), status (string).
Krav: 
constructor initialiserer alle attributer.
objektet er gyldig hvis amount>0 og status =“PLACERET”. 
Implementér en metode - isValid() – som returnerer om objektet er gyldigt (dvs amount >
0 og status har en af følgende værdier: ”PLACERET”, ”PAKKET”, AFSENDT” eller ”LEVERET”. 
Lav derudover en metode – makeValid() – som gør objektet lovligt (amount sættes til 1 og status til
”PLACERET”) hvis det ikke er lovligt (brug isValid() til at checke om det er). 

*/

class Order{
    private:
        int id;
        double amount;
        std::string status;
    public:
        Order(int i, double a, std::string s);
        bool isValid();
        void makeValid();
        void print();
};