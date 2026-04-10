#include <iostream>
#include <string>
using namespace std;

class Dog {
  public:
    string name;
    int age;

    // Complete the constructor
    // It should take a string and an int as parameters
    // and assign them to name and age
    Dog(string n, int a) {
        name = n;
        age = a;
    }

    // Complete the describe() method
    // It should print:
    // Name: [name]
    // Age: [age]
    void describe() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

int main() {
    string name;
    int age;
    cin >> name >> age;

    Dog d(name, age);
    d.describe();
}