#include <iostream>
using namespace std;

class Car{
    private: 
        string model;
        int km;
        int braendstof;
    public: 
    Car(string m, int k, int b){
        model = m;
        km = k;
        braendstof = b;
    }
    void print(){
        cout << "Model: " << model << endl;
        cout << "Kilometer: " << km << endl;
        cout << "Braendstof: " << braendstof << endl;
    }
    void drive (int distance){
        km = km - distance;
        braendstof = braendstof - (distance/10);
    }

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