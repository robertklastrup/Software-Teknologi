#include "Account.h"
#include "Transaction.h"
#include "Bank.h"
#include <iostream>
#include <vector>

int main (){
    string name1;
    string name2;

    cout << "Indtast dit navn: " << endl;
    cin >> name1;
    cout << "Indtast dit navn: " << endl;
    cin >> name2;

    //Vi laver en bank og opretter 2 kontoer
    Bank R;
    R.createAccount (name1);
    R.createAccount (name2);

    //Sætter penge ind på begge konti
    double amount1;
    double amount2;
    cout << "Hvor mange penge skal der være på konti 1?" << endl;
    cin >> amount1;
    cout << "Hvor mange penge skal der være på konti 2?" << endl;
    cin >> amount2;

    for (int i = 0; i < R.accounts.size(); i++){
        if (name1 == R.accounts[i].name){
            R.accounts[i].deposit(amount1);
        }
    }
    for (int i = 0; i < R.accounts.size(); i++){
        if (name2 == R.accounts[i].name){
            R.accounts[i].deposit(amount2);
        }
    }
    double amount3;
    cout << "Hvor meget skal du overfører?" << endl;
    cin >> amount3;

    for(int i = 0; i < R.accounts.size(); i++){
        if (name1 == R.accounts[i].name){
            for(int j = 0; j < R.accounts.size(); j++){
                if (name2 == R.accounts[j].name){
                    R.transfer(R.accounts[i].accountNumber, R.accounts[j].accountNumber, amount3);
                }
            }
        }
    }

    for (int i = 0; i < R.accounts.size(); i++){
        if (name1 == R.accounts[i].name){
            R.findAccount(R.accounts[i].accountNumber);
        }
    }

    string valg;
do {
    cout << "1. Opret konto" << endl;
    cout << "2. Overfør penge til en anden" << endl;
    cout << "3. Se saldo" << endl;
    cout << "4. Se transaktion historik" << endl;
    cout << "q. Afslut" << endl;
    cin >> valg;

    if (valg == "1") {
        for (int i = 0 ; i < R.)
        cout << "Skriv dit fulde navn";
        R.createAccount
    }
    else if (valg == "2") {
       
    }
    else if (valg == "3") {
        
    }
    else if (valg == "4") {
        
    }

} while (valg != "q");
}