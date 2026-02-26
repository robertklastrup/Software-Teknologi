#include    <iostream>
using namespace std;


//En arrays er en samling af variable af samme datatype.
//Arrays har en fast størrelse.



int main () {

    string car[] = {"mercedes", "bmw", "audi", "ferrari"}; //skal være af samme datatype, f.eks. string her.

    car[0] = "toyota";


    //starter fra 0
    cout << car[0] << '\n';
    cout << car[1] << '\n';
    cout << car[2] << '\n';
    cout << car[3] << '\n';

    return 0;
}
