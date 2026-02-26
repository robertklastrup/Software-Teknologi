#include    <iostream>
using namespace std;

// aritmetiske operatorer i C++ returner resultater baseret på matematiske operationer udført på numeriske værdier. (+ - * /)


int main () {

    int students = 20;

    //students = students += 1; // her bruger vi + operatoren til at lægge 1 til værdien af students variablen

    //students += 1; // dette er en kortere måde at skrive det på. Det betyder det samme som linjen over.

    //students++; //Det øger værdien af students med 1.

    //students = students-2; trækker 2 fra
    //students -= 2; trækker 2 fra
    //students--; trækker 1 fra.

    //students = students * 2; ganger med 2
    //students *= 2; ganger med 2

    //students = students / 2; dividerer med 2
    //students /= 2; dividerer med 2

    // int skal ændres til double hvis vi vil have decimaler med i divisionen


    //hvis vi skal lave grupper af 3 studerende og finde ud af hvor mange der er tilovers kan vi bruge modulus operatoren % sådan her:
    int remainder = students % 3;
    
    cout << remainder << '\n';

    return 0;
}