#include    <iostream>
#include   <array>
#include   <string>
#include  <cmath>

using namespace std;

//Null pointers i C++ er pointere, der ikke peger på nogen gyldig hukommelsesadresse.


int main () 
{
    int *pointer = nullptr; // null pointer
    int x = 123;

    //pointer = &x; // pointeren peger nu på x

    if(pointer == nullptr) {
        cout << "Pointeren er en null pointer" << endl;
    } else {
        cout << "Pointeren peger på værdien: " << *pointer << endl;
    }
    
    return 0;
}