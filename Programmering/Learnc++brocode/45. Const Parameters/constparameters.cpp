#include    <iostream>
#include   <array>
#include   <string>
#include  <cmath>

using namespace std;

void printInfo(const string name, const int age);
//const parameters i C++ bruges til at angive, at en funktion ikke må ændre værdien af en parameter, der sendes til den. 
//Dette hjælper med at beskytte data og sikre, at funktioner ikke utilsigtet ændrer inputværdier.

int main () 
{
    string name = "Robert";
    int age = 22;
    printInfo(name, age);   
    
    return 0;
}

void printInfo(const string name, const int age) {
        // name = " "; // This will cause an error because name is a const reference
        // age = 0;    // This will also cause an error because age is a const reference

        cout << name << endl;
        cout << age << endl;
    }