#include "Temperatur.h"
using namespace std;

int main(){
    Temperatur t1 (15);
    Temperatur t2 (13);

    cout << t1 << endl;
    cout << t2 << endl;

    Temperatur t3 = t1 + t2;
    cout << t3 << endl;
    
    cout << (t1 == t2);
    
}