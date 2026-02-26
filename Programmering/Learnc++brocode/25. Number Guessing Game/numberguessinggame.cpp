#include    <iostream>
using namespace std;

int main() {

    int num;
    int guess;
    int tries;

    srand(time(NULL)); 
    num = (rand() % 100) + 1; 

    cout << "***** NUMBER GUESSING GAME*****" << '\n';

    do {
        cout << "Gæt et tal mellem 1 og 100: ";
        cin >> guess;
        tries++; //Inkrement

        if(guess > num) {
            cout << "For højt! Prøv igen." << '\n';
        }
        else if (guess < num) {
            cout << "For lavt! Prøv igen." << '\n';
        }
        else {
            cout << "Tillykke! Du gættede rigtigt på " << tries << " forsøg!" << '\n';
        }
    }while (guess != num);


    cout << "*************************************" << '\n';
    
    return 0;

}