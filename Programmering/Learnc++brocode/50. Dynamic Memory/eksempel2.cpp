#include    <iostream>
using namespace std;

//hvis du kør dette program kan du se at vi definerer størrelsen af vores array som bruger af programmet. 


int main () {
 
    char *pGrades = NULL; //pointer til char der initialiseres til NULL
    int size;

    cout << "Hvor mange karakterer vil du indtaste? ";
    cin >> size;

    pGrades = new char[size]; //allokerer memory til et array af char i heapen

    for(int i = 0; i < size; i++){
        cout << "Indtast karakter " << i + 1 << ": ";
        cin >> pGrades[i];
    }
    cout << "\nDine karakterer er: ";
    for(int i = 0; i < size; i++){
        cout << pGrades[i] << " ";
    }

    delete[] pGrades; //frigør memory allokeret i heapen - skal bruges når der er en "new" for at undgå memory leaks
    return 0;
    
}