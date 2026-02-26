#include    <iostream>
using namespace std;


void happybirthday(string name, int age);
//Vi kan både skrive en funktion før og efter main programmet. Den skal bare deklareres før main programmet.

// en funktion er en blok af kode der er genbrugelig.



// Vi kan nu kalde vores funktion i main programmet sådan her:

int main() {

    string name = "Robert";
    int age = 22;

    happybirthday(name, age);    
    


    return 0;
}

void happybirthday(string name, int age) {
    cout << "Happy birthday to " << name << '\n';
    cout << "Happy birthday to " << name << '\n';
    cout << "Happy birthday dear " << name << "!" << '\n';
    cout << "Happy birthday to " << name << '\n';
    cout << "You are " << age << " years old" << '\n';
}

// Funktioner kan kun se hvad der sker inden for deres eget scope (mellem { } )
// Derfor kan vi ikke bruge variablen name inde i vores funktion happybirthday() som den er skrevet nu.
// For at løse det kan vi sende variablen som et parameter til funktionen sådan
