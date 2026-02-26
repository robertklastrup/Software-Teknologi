#include    <iostream>
using namespace std;

string concatStrings(string string1, string string2);



int main() {
    string fornavn = "Robert";
    string efternavn = "Klastrup";
    string fullname = concatStrings(fornavn, efternavn);

    cout << "hej " << fullname << '\n';
  

    return 0;
}

string concatStrings(string string1, string string2){
    string fullname = string1 + " " + string2;
    return fullname;
}
