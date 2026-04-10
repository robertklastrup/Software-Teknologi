#include <iostream>
using namespace std;


class Engine {
    public:
        int cylinders;
        int horse_power;

    Engine(int c, int hp){
        cylinders = c;
        horse_power = hp;
    }
   
    void print() const{
        cout << "Cylinders: " << cylinders << " Horse Power: " << horse_power << endl;
    }
};

class Car {
    public: 
        string model;
        Engine engine_;
    Car(string m, Engine e) : model(m), engine_(e) {
        model = m;
        engine_ = e;
    }
    void print() const{
        cout << "Model: " << model << " Engine: " ;
        engine_.print();
    }
};

class Mechanic {
    public:
        string name;
        Car* car_;
    Mechanic(string n){
        name = n;
        car_ = nullptr;
    }
    void work_on(Car* c){
        car_ = c;
    }
    void stop_working(){
        car_ = nullptr;
        
    }
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

    m.status();
    m.work_on(&c1);
    m.status();
    m.stop_working();
    m.status();
}