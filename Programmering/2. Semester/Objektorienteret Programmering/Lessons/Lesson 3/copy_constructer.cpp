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

// Car med eksplicit copy-konstruktør:
class Car {
    public:
        string model;
        Engine engine_;

    // sætter model og engine via initializer list:
    Car(string m, Engine e) : model(m), engine_(e) {
        model = m;
        engine_ = e;
    }

    // copy-konstruktør: kopierer model og engine, printer besked:
    Car(const Car& other) : model(other.model), engine_(other.engine_) {
        cout << "Copy constructor kaldt!" << "\n";
    }

    // printer model og kalder engine_.print():
    void print() const{
        cout << "Model: " << model << " Engine: " ;
        engine_.print();
    }
};

int main (){
    Car c1 ("Volvo", Engine(4, 500));
    // c2 oprettes som kopi af c1 via copy-konstruktør:
    Car c2(c1);

    c1.print();
    c2.print();
}
