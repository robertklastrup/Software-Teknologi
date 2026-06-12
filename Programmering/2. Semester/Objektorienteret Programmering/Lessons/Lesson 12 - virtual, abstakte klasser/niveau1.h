#include <iostream>

class Form {
    protected:
        std::string farve;
    public:
        Form (std::string f) : farve(f) {}
        virtual double areal() = 0;
        virtual void print();
};

class Cirkel : public Form{
    private: 
        double radius;
    public:
        Cirkel (std::string f, double r) : Form(f), radius(r){}
        double areal();
        void print ();
};

class Rektangel : public Form{
    private:
        double bredde, hoejde;
    public:
        Rektangel (std::string f, double b, double h) : Form(f), bredde (b), hoejde (h) {}
        double areal();
        void print ();
};