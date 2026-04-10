#pragma once 
#include <string>
#include <vector>
#include "Transaction.h"
#include "Account.h"
using namespace std;


class Bank{
    public:
        vector <Account> accounts;
        void createAccount(string n);
        void findAccount(int a);
        void transfer(int a1, int a2, double a3);
};