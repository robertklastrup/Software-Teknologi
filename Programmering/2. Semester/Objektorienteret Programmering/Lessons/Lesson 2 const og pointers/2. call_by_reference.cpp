#include <iostream>
using namespace std;

// call by pointer: ændrer braendstof direkte via adresse:
void tank (int* braendstof, int liter){
    *braendstof = *braendstof + liter;
}

int main (){
    int braendstof = 20;
    cout << braendstof << endl;
    // sender adressen på braendstof til tank():
    tank(&braendstof, 50);
    cout << braendstof << endl;
}
