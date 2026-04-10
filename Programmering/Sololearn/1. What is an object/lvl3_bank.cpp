#include <iostream>
#include <string>
using namespace std;

// Build your class here
class bankAccount{
    public:
        string Owner;
        int Account;
        double Balance;

    bankAccount(string o, int a, double b){
        Owner = o;
        Account = a;
        Balance = b;
    }

    void deposit (double d){
        Balance = Balance + d;
    }

    void withdraw (double w){
        if (Balance < w){
            cout << "Not enough money, take an L";
        }
        else{
            Balance = Balance - w;
        }
    }

    void describe(){
        cout << "Owner: " << Owner << endl;
        cout << "Account: " << Account << endl;
        cout << "Balance: " << Balance << endl;
        cout << endl; 
    }

};


int main() {
    // Create a BankAccount object
    string Owner = "Robert";
    int Account = 12345;
    double Balance = 15000;
    bankAccount a (Owner, Account, Balance);
    // Deposit some money
    a.deposit (1500);
    // Withdraw some money
    a.withdraw (2000);
    // Call describe()
    a.describe();
}