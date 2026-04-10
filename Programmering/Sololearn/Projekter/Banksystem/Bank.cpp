#include <iostream>
#include <string>
#include <vector>
#include "Transaction.h"
#include "Account.h"
#include "Bank.h"
using namespace std;

    void Bank :: createAccount(string n){
        int a = accounts.size() + 1;
        Account a1 (n,a);
        accounts.push_back(a1);
    }

    void Bank :: findAccount(int a){
        for (int i = 0; i < accounts.size(); i++){
            if(a == accounts[i].accountNumber){
                cout << accounts[i].accountNumber << " "<< accounts[i].name << " Saldo: " << accounts[i].saldo << endl; 
            }
        }
    }
    void Bank :: transfer(int a1, int a2, double a3){
        for (int i = 0 ; i < accounts.size(); i++){
            if (a1 == accounts[i].accountNumber){
                if (a3 < accounts[i].saldo){
                    for (int j = 0 ; j < accounts.size(); j++){
                        if (a2 == accounts[j].accountNumber){
                            accounts[i].withdraw(a3);  // afsender
                            accounts[j].deposit(a3);
                        }
                    }
                }
                else {
                cout << "Der er ikke tilstrækkelige midler på denne konto" << endl;
                }
            }
            
        }
        
    }
