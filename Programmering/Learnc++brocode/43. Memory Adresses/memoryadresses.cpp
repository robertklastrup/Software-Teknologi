#include    <iostream>
#include   <array>
#include   <string>
#include  <cmath>

using namespace std;

// MEMORY ADDRESSES IN C++ is about understanding where data is stored in memory and how to access it using pointers.


int main () 
{
    string name = "Robert";
    int age = 22;
    bool student = true;

    cout << &name << endl;    // prints the memory address of the variable 'name'
    cout << &age << endl;     // prints the memory address of the variable 'age
    cout << &student << endl; // prints the memory address of the variable 'student'

    //kør dette program så kan du se memory adresserne for hver variabel
    
    return 0;
}