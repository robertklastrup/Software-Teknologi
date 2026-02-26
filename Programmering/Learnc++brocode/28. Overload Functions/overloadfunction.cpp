#include    <iostream>
using namespace std;

//Vi kan altså lave et utal af funktioner med samme navn, så længe de har forskellige parametre.
// Dette kaldes function overloading.

void bakePizza();
void bakePizza(string topping1);
void bakePizza(string topping1, string topping2);

int main () {

    bakePizza("pepperoni", "svampe");

    return 0;
}

void bakePizza() {
    cout << "her er din pizza" << '\n';
}

void bakePizza(string topping1) {
    cout << "her er din pizza " << topping1 << '\n';

}



void bakePizza(string topping1, string topping2) {
    cout << "her er din pizza med " << topping1 << " og " << topping2 << '\n';

}