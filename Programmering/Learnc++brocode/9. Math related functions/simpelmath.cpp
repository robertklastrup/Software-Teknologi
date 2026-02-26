#include    <iostream>
using namespace std;

int main() {

    double x = 3;
    double y = 4;
    double z;
    double v;


    z = max(x, y);
    // max funktionen returnerer den største værdi mellem x og y
    v = min(x, y);
    // min funktionen returnerer den mindste værdi mellem x og y
    
    cout << z << '\n';
    cout << v << '\n';

    return 0;
}