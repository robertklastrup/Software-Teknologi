#include    <iostream>
using namespace std;



int main() {

    string name;

    while(name.empty()) {
        cout << "Skriv dit navn: " << '\n';
        getline(cin, name);
    }
    //while loopet fortsætter med at bede brugeren om at indtaste deres navn, indtil de rent faktisk skriver noget 
    //(dvs. indtaster en ikke-tom streng)
    //getline bruges til at læse hele linjen inklusive mellemrum

    cout << "Velkommen " << name << "!" << '\n';
    return 0;


};



// Omskrevet til et for loop:

//for(string name = " "; name.empty(); ) {
//    cout << "Skriv dit navn: " << '\n';
//    getline(cin, name);
//};
