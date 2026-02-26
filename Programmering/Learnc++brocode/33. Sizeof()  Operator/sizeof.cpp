#include    <iostream>
using namespace std;

//sizeof() operatoren returnerer størrelsen af en datatype eller et objekt i bytes.

int main () {

    string name = "Robert"; //string (object) 32 bytes (på en 64-bit maskine)
    double gpa = 2.5; //double 8 bytes
    char grade = 'A';
    bool student = true; //bool 1 byte
    char grades [] = {'A', 'B', 'C', 'D', 'F'}; //char 1 byte

    string names [] = {"Anna", "Bob", "Charlie"}; //string (object) 32 bytes hver

    //cout << sizeof(grades) << " bytes" << '\n';
    
    cout << sizeof(names)/sizeof(string) << " elements" << '\n';

    return 0;
}