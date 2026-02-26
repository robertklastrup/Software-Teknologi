#include    <iostream>
#include    <vector>
using namespace std;


//typedef vector<pair<string,int>>pairlist_t;

//Vi kan give dette et alias altså pairlist_t som er en vector der indeholder par af string og int værdier.

//Det kan vi bruge i vores mainprogram som sådan her:



typedef string text_t;
typedef int number_t;
//Her har vi defineret to aliaser: text_t som et alias for string typen
//og number_t som et alias for int typen.

//Man kan også bare lave det som en 'using' erklæring som sådan her:
//using text_t = string;
//using number_t = int;


int main() {

    text_t navn = "Robert";
    // dette er altså en string variabel fordi vi har defineret text_t som et alias for string typen.

    number_t alder = 22;
    // dette er altså en int variabel fordi vi har defineret number_t som et
    
    cout << navn << '\n';
    cout << alder << '\n';

    return 0;
}
