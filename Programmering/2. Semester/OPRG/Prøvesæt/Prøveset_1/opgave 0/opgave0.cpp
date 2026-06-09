#include "opgave0.h"
#include <vector>
using namespace std;

bool studieeffektivt(int a){
    vector<int> result;
    //Først laver vi vores int til en string
    string as = to_string(a);
    //Vi opretter sum, til at gemme summen af cifrene i vores loop
    int sum = 0;

    //Vi laver et forloop der går vores string igennem, ændre cifrene til int, og ligger dem i summen
    for (int i = 0; i < as.length(); i++){
        sum = sum + (as[i] - '0');
    }

    //Vi returnerer true hvis vores int "sum" kan divideres med 3
    if (sum % 3 == 0){
        result.push_back(a);
        return true;
    }
    else{return false;}

}

vector <int> studieeffektiveTal(int fra, int til){
    vector<int> result;
    for (int i = fra; i <= til; i++){
        if (studieeffektivt(i)){
            result.push_back(i);
        }
    }
    return result;
}