#include    <iostream>
using namespace std;


// et foreach loop = loop som gennemløber elementerne i en array eller en samling
// bruges ofte til at gennemløbe arrays eller samlinger uden at skulle bruge en tæller

int main () {

    //mit iterable dataset:
    string students [] = {"Anna", "Bob", "Charlie", "David", "Eva"};

    for (string student : students){
        cout << student << '\n';
        
    }
    //foreach loopet ovenfor gør det samme som for-løkken i iterate.cpp filen.

    return 0;
}