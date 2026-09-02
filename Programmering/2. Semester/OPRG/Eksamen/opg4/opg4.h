#include <iostream>
#include <vector>


/*
Du skal lave en funktion i C++ som beregner gennemsnittet af en række ordres beløb (amount) fra
forrige opgave. 
Udover rækken af ordre skal funktionen også have parametre der angiver for hvilket id
interval der skal beregnes gennemsnit. 
Hvordan vil du repræsentere rækken af ordre? 
Hvilke alternativer overvejer du? Og hvorfor vælger du netop denne repræsentation? 

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
        int getID();
        double getAmount();
};

double gennemsnit(std::vector<Order> ordre, int i);