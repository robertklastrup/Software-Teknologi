#include    <iostream>
using namespace std;

// en fill funktion fylder et array med en bestemt værdi




int main () {
    
    const int size = 99;
    string foods[size]; 

    fill(foods, foods + (size/3), "Pizza");
    fill(foods + (size/3), foods + (size/3)*2, "Burger");
    fill(foods + (size/3)*2, foods + size, "Hotdog");

    for (string food : foods) {
        cout << food << " "<< '\n';
    }

    
    return 0;
}