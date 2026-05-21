#include <iostream>
using namespace std;

int main (){

    int braendstof = 40;
    // reference: braendstof_ref er alias for braendstof (samme adresse):
    int& braendstof_ref = braendstof;

    cout << braendstof << endl;
    cout << braendstof_ref << endl;

    // ændring via reference påvirker original:
    braendstof_ref = 80;

    cout << braendstof << endl;
    cout << braendstof_ref << endl;

    return (0);
}
