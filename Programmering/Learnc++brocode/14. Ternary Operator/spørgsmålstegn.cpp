#include    <iostream>
using namespace std;

//Ternary operator  ? :  = en kortere måde at skrive et if/else statement på.
// syntax: condition ? expression1(true) : expression2(false);




int main() {
    
    int grade = 75;

    //if (grade >= 60){
    //    cout << "Bestået" << '\n';
    //}
    //else {
    //    cout << "Ikke bestået" << '\n';
    //}
    //kan omskrives til:
    //grade >= 60 ? cout << "Bestået" << '\n' : cout << "Ikke bestået" << '\n';

    //int number = 9;
    //number % 2 ? cout << "ulige tal" << '\n' : cout << "lige tal" << '\n';
    //Her tjekker vi om tallet er ulige eller lige ved hjælp af modulus operatoren %.

    bool hungry = true;
    //hungry == true ? cout << "Spis noget mad" << '\n' : cout << "Fortsæt med at arbejde" << '\n';

    cout << (hungry ? "Spis noget mad" : "Du er mæt") << '\n';

    return 0;
}