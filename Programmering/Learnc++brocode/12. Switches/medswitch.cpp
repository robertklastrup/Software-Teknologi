#include    <iostream>
using namespace std;


int main() {
    
    int month;
    cout << "Indtast et måned nummer (1-12): ";
    cin >> month;

    switch(month){
        case 1:
            cout << "Januar" << '\n';
            break;
        case 2:
            cout << "Februar" << '\n';  
            break;
        case 3:
            cout << "Marts" << '\n';
            break;
        case 4:
            cout << "April" << '\n';    
            break;
        case 5:
            cout << "Maj" << '\n';
            break;  
        case 6:
            cout << "Juni" << '\n';
            break;
        case 7:
            cout << "Juli" << '\n';
            break;
        case 8:
            cout << "August" << '\n';
            break;  
        case 9:
            cout << "September" << '\n';    
            break;
        case 10:
            cout << "Oktober" << '\n';
            break;
        case 11:
            cout << "November" << '\n';
            break;
        case 12:
            cout << "December" << '\n';
            break;
        default:
            cout << "Venligst kun indtast måneder 1-12" << '\n';
            break;

    }

    return 0;

}