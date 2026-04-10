#include <iostream>
using namespace std;



int main (){
    int km = 15000;
    int* km_ptr{&km};
    cout << km_ptr << endl;
    cout << *km_ptr << endl;
    *km_ptr = 16000;
    cout << km << endl;
}
