#include <iostream>
using namespace std;

// Engine-klasse med cylindre og hestekræfter:
class Engine {
    public:
        int cylinders;
        int horse_power;

    // sætter cylindre og hestekræfter:
    Engine(int c, int hp){
        cylinders = c;
        horse_power = hp;
    }

    // printer motor-info:
    void print() const{
        cout << "Cylinders: " << cylinders << " Horse Power: " << horse_power << endl;
    }
};

// Car-klasse der indeholder Engine (composition):
class Car {
    public:
        string model;
        Engine engine_;

    // sætter model og engine via initializer list:
    Car(string m, Engine e) : model(m), engine_(e) {
        model = m;
        engine_ = e;
    }

    // printer model og kalder engine_.print():
    void print() const{
        cout << "Model: " << model << " Engine: " ;
        engine_.print();
    }
};

int main (){
    Car c1 ("Volvo", Engine(4, 150));
    Car c2("BMW", Engine(6, 300));

    c1.print();
    c2.print();

    // assignment: kopierer c1 (inkl. engine) ind i c2:
    c2 = c1;

    c1.print();
    c2.print();

}
