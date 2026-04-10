#include <iostream>
using namespace std;

int main (){
    
    int braendstof = 40;
    int& braendstof_ref = braendstof;

    cout << braendstof << endl;
    cout << braendstof_ref << endl;

    braendstof_ref = 80;

    cout << braendstof << endl;
    cout << braendstof_ref << endl;

    return (0);
}