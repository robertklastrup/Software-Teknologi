#include <iostream>
using namespace std;


void tank (int* braendstof, int liter){
    *braendstof = *braendstof + liter;
}

int main (){
    //Første forsøg:
    /*
    int braendstof = 20;
    int* braendstof_ptr{&braendstof};
    cout << *braendstof_ptr << endl;
    tank(braendstof_ptr, 50);
    cout << *braendstof_ptr << endl;
    */

    int braendstof = 20;
    cout << braendstof << endl;
    tank(&braendstof, 50);
    cout << braendstof << endl;


}

