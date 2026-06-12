#include <iostream>



class Dyr{
    private:
        std::string navn;
        int alder;
    public:
        Dyr(std::string n, int a) : navn(n), alder(a){}
        void print ();
};



class Hund : public Dyr{
    private:
        std::string race;
    public:
        Hund(std::string n, int a, std::string r) : Dyr (n, a), race(r){}
        void print();
};