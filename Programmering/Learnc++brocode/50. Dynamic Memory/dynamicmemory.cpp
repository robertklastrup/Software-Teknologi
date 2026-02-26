#include    <iostream>
#include   <array>
#include   <string>
#include  <cmath>

using namespace std;


//dynamic memory er memory der allokeres under kørselstidspunktet (runtime)
//bruges når man ikke kender størrelsen af et array på forhånd eller hvis man arbejder med store datamængder


int main () 
{
    int *pNum = NULL;

    pNum = new int; //allokerer memory til en integer i heapen

    *pNum = 42;
    cout << "Adresse: " << pNum << '\n'; //viser adressen i heapen hvor integeren er allokeret
    cout << "Værdi: " << *pNum << '\n'; //dereferencering af pointeren

    delete pNum; //frigør memory allokeret i heapen - skal bruges når der er en "new" for at undgå memory leaks

    return 0;
}