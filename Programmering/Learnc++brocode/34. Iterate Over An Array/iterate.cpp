#include    <iostream>
using namespace std;

//iterate over an array gør det muligt at gennemløbe alle elementerne i en array ved hjælp af en løkke.

int main () {

    string students [] = {"Anna", "Bob", "Charlie", "David", "Eva"};

    //cout << students[0] << '\n';
    //cout << students[1] << '\n';
    //cout << students[2] << '\n';
    //cout << students[3] << '\n';
    //cout << students[4] << '\n';

    //man kan også bruge en for-løkke til at gennemløbe arrayet:
    //for (int i = 0; i < 5; i++){
    //    cout << students[i] << '\n';
    //}
    //kommer der flere navne i vores arrat, skal vi huske at ændre 5-tallet i for-løkken til det nye antal elementer.

    //Derfor kan man bruge sizeof() operatoren til at finde antallet af elementer i arrayet:
    for (int i = 0; i < sizeof(students) / sizeof(string); i++){
        cout << students[i] << '\n';
    }



    return 0;
}