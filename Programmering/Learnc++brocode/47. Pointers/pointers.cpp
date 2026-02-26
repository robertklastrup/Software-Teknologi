#include    <iostream>
#include   <array>
#include   <string>
#include  <cmath>

using namespace std;

// en pointer er en variabel, der gemmer memory adressen til en anden variabel
// vi bruger dem til at få adgang til og manipulere data i hukommelsen direkte
//& adress of operator
// * dereference operator


int main () 
{
    //Husk at pointers skal have samme datatype som den variabel de peger på
    string name = "Robert";
    int age = 22;

    string *pName = &name; // pointer til string variablen name
    int *pAge = &age;      // pointer til int variablen age

    cout << pName << '\n'; // printer memory adressen til name
    cout << *pName << '\n'; // dereference pointeren for at få værdien af name

    cout << pAge << '\n'; // printer memory adressen til age
    cout << *pAge << '\n'; // dereference pointeren for at få værdien af age

    return 0;
}