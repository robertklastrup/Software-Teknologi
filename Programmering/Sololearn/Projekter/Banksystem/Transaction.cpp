#include "Transaction.h"
#include <iostream>
using namespace std;


Transaction::Transaction(string t, double a, string d) {
    type = t;
    amount = a;
    description = d;
}