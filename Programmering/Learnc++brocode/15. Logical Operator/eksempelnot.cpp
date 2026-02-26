#include        <iostream>
using namespace std;


//Logical Operators = bruges til at kombinere betingelser/udtryk
// && tjekker om 2 betingelser er sande (AND)
// || tjekker om mindst 1 betingelse er sand (OR)
// !  vender en betingelse om (NOT)

int main() {

    int temp;
    bool sunny = true;

    cout << "Indtast temperaturen: ";
    cin >> temp;

    if (temp > 0 && temp < 30){
        cout << "Det er en behagelig temperatur" << '\n';
    }
    else {
        cout << "Det er ikke en behagelig temperatur" << '\n';
    }

    if(!sunny == true){
        cout << "Det er ikke solrigt udenfor" << '\n';
    }
    else {
        cout << "Det er solrigt udenfor" << '\n';
    }

    return 0;
}