#include    <iostream>
using namespace std;

int main() {
    const double pi = 3.14159; //deklaration og initialisering af konstant variabel pi, så den ikke kan ændres
    const int LIGHT_SPEED = 299792458; //lys hastighed i meter per sekund som en konstant variabel
    const int WIDTH = 1920; //skærmbredde som en konstant variabel
    const int HEIGHT = 1080; //skærmhøjde som en konstant variabel

    int skærmopløsning = WIDTH * HEIGHT; //beregning af skærmopløsning ved hjælp af de konstante variabler WIDTH og HEIGHT
    cout << "Din skærmopløsning er: " << skærmopløsning << " pixels" << '\n'; //udskrivning af skærmopløsning til konsollen
    cout << "Lys hastighed er: " << LIGHT_SPEED << " meter per sekund" << '\n'; //udskrivning af lys hastighed til konsollen

    
    return 0;
}