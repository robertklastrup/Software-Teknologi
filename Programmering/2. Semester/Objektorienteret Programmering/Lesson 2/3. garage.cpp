#include <iostream>
using namespace std;

// Car-klasse med model, km og brændstof:
class Car{
    private:
        string model;
        int km;
        int braendstof;
    public:

    // sætter model, km og brændstof:
    Car(string m, int k, int b){
        model = m;
        km = k;
        braendstof = b;
    }

    // printer bil-info:
    void print(){
        cout << "Model: " << model << endl;
        cout << "Kilometer: " << km << endl;
        cout << "Braendstof: " << braendstof << endl;
    }

    // trækker distance fra km og bruger brændstof:
    void drive (int distance){
        km = km - distance;
        braendstof = braendstof - (distance/10);
    }

    // tilføjer liter brændstof:
    void tank_op (int liter){
        braendstof = braendstof + liter;
    }
};



int main (){
    Car c1 ("Goatmobilen", 50000, 30);
    c1.print();
    c1.drive(200);
    c1.tank_op(30);
    c1.print();

    return (0);
}
