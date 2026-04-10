#include "Account.h"
#include "Transaction.h"
#include "Bank.h"
#include <iostream>
#include <vector>


int main(){
    Bank R;
    string valg;

    do {
        cout << "1. Opret konto" << endl;
        cout << "2. Tilføj penge til konto" << endl;
        cout << "3. Træk penge fra konto" << endl;
        cout << "4. Overfør penge til en anden" << endl;
        cout << "5. Se saldo" << endl;
        cout << "6. Se transaktion historik" << endl;
        cout << "q. Afslut" << endl;
        cin >> valg;

        if (valg == "1") {
            string navn;
            cout << "Skriv dit fulde navn" << endl;
            cin.ignore();
            getline(cin, navn);
            R.createAccount(navn);
        }
        else if (valg == "2") {
            double a;
            int b;
            cout << "Hvilken konto vil du sætte penge ind på?" << endl;
            cin >> b;
            cout << "Hvor meget vil du sætte ind på denne konti?" << endl;
            cin >> a;
            for(int i = 0; i < R.accounts.size(); i++){
                if (b == R.accounts[i].accountNumber){
                    R.accounts[i].deposit(a);
                }
            }
        }
        else if (valg == "3") {
            double a;
            int b;
            cout << "Hvilken konto vil du trække penge fra?" << endl;
            cin >> b;
            cout << "Hvor meget vil du trække ud af denne konti?" << endl;
            cin >> a;
            for(int i = 0; i < R.accounts.size(); i++){
                if (b == R.accounts[i].accountNumber){
                    R.accounts[i].withdraw(a);
                }
            }
        }
        else if (valg == "4") {
            int a1;
            int a2;
            double a3;
    
            cout << "Hvilken konto vil du overfører penge fra?" << endl;
            cin >> a1;
            cout << "Hvilken konto vil du overfører penge til?" << endl;
            cin >> a2;
            cout << "Hvor meget vil du overføre?" << endl;
            cin >> a3;

            R.transfer(a1, a2, a3);
        }
        else if (valg == "5") {
            int kontonummer;
            cout << "Indtast dit kontonummer" << endl;
            cin >> kontonummer;
            for (int i = 0; i < R.accounts.size(); i++){
                if (kontonummer == R.accounts[i].accountNumber){
                    cout << R.accounts[i].saldo << endl;
                }
            }
        }
        else if (valg == "6") {
            int kontonummer;
            cout << "Indtast dit kontonummer" << endl;
            cin >> kontonummer;
            for (int i = 0; i < R.accounts.size(); i++){
                if (kontonummer == R.accounts[i].accountNumber){
                    R.accounts[i].printHistory();
                }
            }
        }

    } while (valg != "q");

}