#include <iostream>
#include <string>
using namespace std;

class Car {
  public:
    string brand;
    string model;
    int year;

    // Complete the constructor
    // It should take brand, model and year as parameters
    Car(string b, string m, int y) {
        brand = b;
        model = m;
        year = y;
    }

    // Complete the describe() method
    // It should print brand, model and year
    // Remember a blank line at the end!
    void describe() {
        cout << "Brand: "<< brand << endl;
        cout << "Model: "<< model << endl;
        cout << "Year: "<< year << endl;
        cout << endl;
    }
};

int main() {
    // Create two Car objects here with different values
    // and call describe() on both of them
    string brand1;
    string model1;
    int year1;
    cout << "Skriv bil brand på bil 1:" << endl;
    cin >> brand1;
    cout << "Skriv bil model på bil 1:" << endl;
    cin >> model1;
    cout << "Skriv bilens årgang på bil 1:" << endl;
    cin >> year1;

    string brand2;
    string model2;
    int year2;
    cout << "Skriv bil brand på bil 2:" << endl;
    cin >> brand2;
    cout << "Skriv bil model på bil 2:" << endl;
    cin >> model2;
    cout << "Skriv bilens årgang på bil 2:" << endl;
    cin >> year2;

    Car a (brand1, model1, year1);
    Car b (brand2, model2, year2);
    a.describe();
    b.describe();

}