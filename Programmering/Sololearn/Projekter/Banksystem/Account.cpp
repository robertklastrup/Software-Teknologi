#include <iostream>
#include "Account.h"
#include "Transaction.h"
#include <vector>
#include <string>
using namespace std;

    Account :: Account (string n, int a){
        name = n;
        accountNumber = a;
        saldo = 0;
    }
    void Account :: deposit (double a){
        saldo = saldo + a;
        Transaction t ("Deposit", a, "Has been deposited to account");
        transactions.push_back(t);
    }
    void Account :: withdraw (double a){
        if (saldo <= a){
            cout << "Not enough money on account" << endl;
        }
        else{
            saldo = saldo - a;
            Transaction t ("Withdraw", a, "Has been withdrawed from account");
            transactions.push_back(t);
        }
    }
    void Account :: printHistory(){
        for (int i = 0; i < transactions.size();i++){
            cout << transactions[i].type << ": " << transactions[i].amount << ". " << transactions[i].description << endl;
        }
    }
