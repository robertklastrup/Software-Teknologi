#include <iostream>
using namespace std;


class Car{
    public:
        string model;
        int km;
        int braendstof;

    Car(string m, int k, int b){
        model = m;
        km = k;
        braendstof = b;
    }
    void print() const{
        cout << " Model: " << model << "     Kilometer: " << km << "     Braendstof: " << braendstof << endl;
    }
    string getmodel() const{
        return(model);
    }
};
void drive (Car& bil, int distance){
    bil.km = bil.km - distance;
    bil.braendstof = bil.braendstof - (distance/10);
}
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
