#include    <iostream>
using namespace std;


int main() {
    
    int month;
    cout << "Indtast et måned nummer (1-12): ";
    cin >> month;

    if (month == 1) {
        cout << "Januar" << '\n';
    }
    else if (month == 2) {
        cout << "Februar" << '\n';
    }
    else if (month == 3) {
        cout << "Marts" << '\n';
    }
    else if (month == 4) {
        cout << "April" << '\n';
    }
    else if (month == 5) {
        cout << "Maj" << '\n';
    }
    else if (month == 6) {
        cout << "Juni" << '\n';
    }
    else if (month == 7) {
        cout << "Juli" << '\n';
    }
    else if (month == 8) {
        cout << "August" << '\n';
    }
    else if (month == 9) {
        cout << "September" << '\n';
    }
    else if (month == 10) {
        cout << "Oktober" << '\n';
    }
    else if (month == 11) {
        cout << "November" << '\n';
    }
    else if (month == 12) {
        cout << "December" << '\n';
    }
    else {
        cout << "Ugyldigt måned nummer!" << '\n';
    }

    return 0;

}