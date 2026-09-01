#include <iostream>
#include <vector>


/*
Ordrerne er ordre i et firma. 
Lav en klasse – Firma – som har en række ordre og et navn. 
Det skal være muligt at beregne gennemsnits beløbet i et firma 
(implementeringen skal bruge funktionen fra opgave 4) 
som er afsendt fra firmaet (dvs har enten status ”AFSENDT” eller ”LEVERET”) 
samt oprette en ordre (metode på Firma). 
Hvilken sammenhæng har du valgt mellem Order og Firma og hvorfor?
Derudover skal du implementere en ny type, der kan indeholde de lovlige værdier for en ordre. Benyt
denne type i Order og ret funktionen fra opgave 4 samt klasen Firma. 
*/
enum Status{
    PLACERET,
    PAKKET,
    AFSENDT,
    LEVERET
};


class Order{
    private:
        int id;
        double amount;
        Status status;
    public:
        Order(int i, double a, Status s);
        bool isValid();
        void makeValid();
        void print();
        int getID();
        double getAmount();
        Status getStatus();
};

double gennemsnit(std::vector<Order> ordre);

class Firma{
    private:
        std::vector<Order> ordre;
        std::string navn;
    public:
        Firma(std::string n, std::vector<Order> o);
        double firma_gennemsnit();
        void opretOrdre(Order o);
};