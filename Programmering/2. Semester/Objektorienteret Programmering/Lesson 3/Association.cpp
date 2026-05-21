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

// Car indeholder Engine (composition):
class Car {
    public:
        string model;
        Engine engine_;

    // sætter model og engine:
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

// Mechanic peger på en Car (association: løs kobling via pointer):
class Mechanic {
    public:
        string name;
        Car* car_;

    // sætter navn og sætter car_ til nullptr:
    Mechanic(string n){
        name = n;
        car_ = nullptr;
    }

    // peger car_-pointer på given bil:
    void work_on(Car* c){
        car_ = c;
    }

    // sætter car_-pointer til nullptr (på pause):
    void stop_working(){
        car_ = nullptr;

    }

    // printer om mekanikeren arbejder eller er på pause:
    void status() const{
        if (car_ == nullptr){
            cout << name << ": Paa pause" << endl;
        }
        else{
            cout << name << ": Working on: " << car_->model << endl;

        }
    }
};


int main (){
    Car c1 ("Volvo", Engine(4,150));
    Mechanic m ("Bob");

    // viser status, sætter Bob til at arbejde, stopper igen:
    m.status();
    m.work_on(&c1);
    m.status();
    m.stop_working();
    m.status();
}
