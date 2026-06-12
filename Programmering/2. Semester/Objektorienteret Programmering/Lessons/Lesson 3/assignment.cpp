#include <iostream>
using namespace std;

// Car-klasse med model og km:
class Car {
    public:
        string model;
        int km;

    // sætter model og km:
    Car(string m, int k){
        model = m;
        km = k;
    }

    // printer model og km:
    void print() const{
        cout << "Model: " << model << " Kilometer: " << km << endl;
    }
};

int main(){
    Car c1 ("Volvo", 50000);
    Car c2 ("BMW", 20000);

    c1.print();
    c2.print();

    // assignment: kopierer c1's værdier ind i c2:
    c2 = c1;

    c1.print();
    c2.print();

}
