#include <iostream>
using namespace std;

// Car-klasse med model, km og brændstof:
class Car{
    public:
        string model;
        int km;
        int braendstof;

    // sætter model, km og brændstof:
    Car(string m, int k, int b){
        model = m;
        km = k;
        braendstof = b;
    }

    // const: printer bil-info uden at ændre objektet:
    void print() const{
        cout << " Model: " << model << "     Kilometer: " << km << "     Braendstof: " << braendstof << endl;
    }

    // const: returnerer model uden at ændre objektet:
    string getmodel() const{
        return(model);
    }
};

// call by reference: ændrer km og brændstof direkte:
void drive (Car& bil, int distance){
    bil.km = bil.km - distance;
    bil.braendstof = bil.braendstof - (distance/10);
}

// call by reference: tilføjer liter brændstof direkte:
void tank_op (int& braendstof, int liter){
    braendstof = braendstof + liter;
}

int main (){
    Car c1 ("Goatmobilen", 10000, 30);

    c1.print();

    drive(c1, 500);
    tank_op(c1.braendstof, 45);

    c1.print();

    cout << "Bilens model er: "<< c1.getmodel() << endl;

    return(0);
}
