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
    Car(const Car& other) : model(other.model), engine_(other.engine_) {
        cout << "Copy constructor kaldt!" << "\n";
    }
    void print() const{
        cout << "Model: " << model << " Engine: " ;
        engine_.print();
    }
};

int main (){
    Car c1 ("Volvo", Engine(4, 500));
    Car c2(c1);

    c1.print();
    c2.print();
}