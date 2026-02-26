#include    <iostream>
using namespace std;





int main () 
{
    string foods[5];

    int size = sizeof(foods) / sizeof(foods[0]);
    string temp;

    for (int i = 0; i < size; i++) 
    {
        cout << "Enter a food you like or 'q' to quit " << i  << ": ";
        getline(cin, temp);
        //funktion til at afslutte program:
        if (temp == "q") {
            break;
        } else {
            foods[i] = temp;
        }
    }

    cout << "you like the following foods: " << '\n';

    //denne funktion sørger for der ikke er noget empty space. 
    //Da der er 5 pladser i vores array, vil den vise nogle pladsholdere, som bare er tomrum. Det vil vi gerne fjerne således:
    
    for (int i = 0; foods[i].empty(); i++) 
    {
        cout << foods[i] << " " << '\n';
    }

    return 0;

}