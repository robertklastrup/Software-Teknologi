#pragma once 
#include <string>
#include <vector>
#include "Transaction.h"
using namespace std;



class Account{
    public:
        string name;
        int accountNumber;
        double saldo;
        vector <Transaction> transactions;
    Account (string n, int a);
    void deposit (double a);
    void withdraw (double a);
    void printHistory();
};