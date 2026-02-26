#include    <iostream>
using namespace std;

//if statement = en betingelse der udfører en blok af kode hvis betingelsen er sand (true)
// if not, så udføres koden ikke.

int main() {
   
    int age;

    cout << "Indtast din alder: ";
    cin >> age;


    if (age >= 100){
        cout << "Du er for gammel til at komme ind på dette site" << '\n';
    }
    else if (age>=18){
        cout << "Velkommen til vores site!" << '\n';
    }
    else if (age < 0){
        cout << "Du er ikke født endnu" << '\n';
    }
    else {
        cout << "Du er ikke gammel nok til at komme ind på dette site" << '\n';
    }

    return 0;
}