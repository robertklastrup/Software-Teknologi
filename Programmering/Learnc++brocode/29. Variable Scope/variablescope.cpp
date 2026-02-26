#include    <iostream>
using namespace std;

//Lokale variabler er variabler deklareret indenfor en funktion
// Global variabler er variabler deklareret udenfor alle funktioner


//num er en lokal variabel, da du sådan set kan ændre værdi fra funktion til funktion. 
//myNum er global da den er uden for alle funktioner


int myNum = 20; //global variabel


void printNum(int num);

int main () {

    int num = 10; //global variabel
    
    printNum(num);
    
    printNum(myNum);
    
    return 0;
}

void printNum(int num) {
    cout << num << '\n';
}