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
    Car(string m, Engine e){
        model = m;
        engine_ = e;
    }
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

    c2 = c1;

    c1.print();
    c2.print();

}