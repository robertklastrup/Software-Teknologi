#include <iostream>
using namespace std;

class Car {
    public:
        string model;
        int km;
    Car(string m, int k){
        model = m;
        km = k;
    }
    void print() const{
        cout << "Model: " << model << " Kilometer: " << km << endl;
    }  
};

int main(){

    Car c1 ("Volvo", 50000);
    Car c2 ("BMW", 20000);

    c1.print();
    c2.print();

    c2 = c1;

    c1.print();
    c2.print();
    
}