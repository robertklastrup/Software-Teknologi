#pragma once  // forhindrer at filen inkluderes flere gange
#include <string>
using namespace std;

class Transaction {
public:
    // attributter
    string type;
    double amount;
    string description;

    // constructor
    Transaction(string t, double a, string d);
};