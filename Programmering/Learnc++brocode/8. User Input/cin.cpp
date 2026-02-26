#include   <iostream>
using namespace std;

//cout << (det vi viser brugeren)
//cin >> (det brugeren indtaster)

int main() {
    string navn;
    int alder;
    
    cout << "Hvor gammel er du?";
    cin >> alder;

    cout << "Hvad er dit fulde navn";
    getline(cin >> ws, navn);
    
    cout << "hej " << navn;
    cout << ", du er " << alder << "år gammel!";
    
    return 0;

}