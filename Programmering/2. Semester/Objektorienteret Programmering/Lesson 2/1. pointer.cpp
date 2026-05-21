#include <iostream>
using namespace std;



int main (){
    int km = 15000;
    // pointer: variabel der gemmer adressen på km:
    int* km_ptr{&km};
    // printer adressen på km:
    cout << km_ptr << endl;
    // printer værdien via dereference:
    cout << *km_ptr << endl;
    // ændrer km's værdi via pointer:
    *km_ptr = 16000;
    cout << km << endl;
}
