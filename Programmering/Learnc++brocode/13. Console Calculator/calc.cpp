#include    <iostream>
using namespace std;

int main() {

    char op;
    double num1;
    double num2;
    double result;

    cout << "***** CALCULATOR *****" << '\n';

    cout << "Indtast et operator (+, -, *, /): ";
    cin >> op;

    cout << "Indtast tal 1: ";
    cin >> num1;

    cout << "Indtast tal 2: ";
    cin >> num2;

    switch(op){
        case '+':
            result = num1 + num2;
            cout << num1 << " + " << num2 << " = " << result << '\n';
            break;
        case '-':
            result = num1 - num2;
            cout << num1 << " - " << num2 << " = " << result << '\n';
            break;
        case '*':
            result = num1 * num2;
            cout << num1 << " * " << num2 << " = " << result << '\n';
            break;
        case '/':
            if (num2 != 0){
                result = num1 / num2;
                cout << num1 << " / " << num2 << " = " << result << '\n';
            }
            else {
                cout << "Fejl: Division med nul er ikke tilladt." << '\n';
            }
            break;
        default:
            cout << "Ugyldig operator!" << '\n';
            break;
    }

    cout << "**********************" << '\n';

    return 0;
}