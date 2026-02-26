#include    <iostream>
using namespace std;

double getTotal(double priser[], int size);

int main () {

    double priser[] = {199.99, 299.99, 399.99, 499.99, 599.99};
    int size = sizeof(priser) / sizeof(priser[0]);
    double sum = getTotal(priser, size);

    cout << "Den samlede pris er: " << sum << " kr." << '\n';

    return 0;
}

double getTotal(double priser[], int size){
    double total = 0;
    for(int i = 0; i < size; i++){
        total += priser[i];
    }
    return total;
}