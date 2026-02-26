#include <iostream>
#include <ctime>
using namespace std;


int main (){
    bool adgang;
    bool harVIP;
    int alder;
    char billet;
    
    char VIP;

    char alkohol;
 
    double penge;
    char beruset;
  
    double klokken;

    cout << "Hvor gammel er du?" << '\n';
    cin >> alder;

    cout << "Har du billet? (J/N)" << '\n';
    cin >> billet;

    cout << "Har du VIP billet? (J/N)" << '\n';
    cin >> VIP;
 
    cout << "Har du alkohol med? (J/N)" << '\n';
    cin >> billet;

    cout << "Hvor mange penge har du?" << "\n";
    cin >> penge;

    cout << "Er du beruset? (J/N)" << '\n';
    cin >> beruset;

    cout << "Hvad er klokken?" << '\n';
    cin >> klokken;

    void adgangskontrol () {
        if (billet == 'j' || billet == 'J'){
            adgang = true;
        }
        else if (alder >= 16){
            adgang = true;
        }
        else if (beruset = "j" || "J"){
            adgang = true;
        }
        else if ()


    }






}