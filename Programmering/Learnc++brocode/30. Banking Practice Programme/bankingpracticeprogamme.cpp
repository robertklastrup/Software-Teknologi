#include    <iostream>
#include   <string>
#include  <iomanip>
using namespace std;

//Funktioner
void showBalance(double balance);
double deposit();
double withdraw(double balance);



int main() {

    double balance = 1500.00;
    int choice = 0;


    do{
        cout << "***** BANKING PRACTICE PROGRAM *****" << '\n';
        cout << "Indtast dit valg: " << '\n';
        cout << "-------------------------------" << '\n';
        cout << "1. Vis saldo" << '\n';
        cout << "2. Indsæt penge" << '\n';
        cout << "3. Hæv penge" << '\n';
        cout << "4. Afslut" << '\n';
        cin >> choice;

        switch(choice) {
            case 1: showBalance(balance);
                break;
            case 2: balance += deposit();
                break;
            case 3: balance -= withdraw(balance);
                break;
            case 4: cout << "Tak for at bruge vores bank program!" << '\n';
                break;
            default: cout << "Ugyldigt valg! Prøv igen." << '\n';
        }
    }while(choice != 4);
    

    return 0;
}


void showBalance(double balance) {
    cout << "Din nuværende saldo er: " << setprecision(2) << fixed << balance << " kr." << '\n';
    
}

double deposit(){
    
    double amount = 0;
    cout << "Indtast beløbet du vil indsætte: ";
    cin >> amount;
    
    if(amount > 0){
        return amount;
    } 
    else {
        cout << "Ugyldigt beløb! Prøv igen." << '\n';
        return 0;
    }
    
}

double withdraw(double balance){

    double amount = 0;

    cout << "Indtast beløbet du vil hæve: ";
    cin >> amount;
    
    if (amount > balance) {
        cout << "Utilstrækkelig saldo! Prøv igen." << '\n';
        return 0;
    } 
    else if (amount <= 0) {
        cout << "Ugyldigt beløb! Prøv igen." << '\n';
        return 0;
    }
    else {
        return amount;
    }
    return 0;
    
}
