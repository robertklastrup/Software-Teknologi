#include <iostream>
#include <vector>
using namespace std;

//Hvad skal jeg:
// ud fra min vector funktion skal jeg lave en function der returnerer max elementet i vectoren

template <class T>
T max (vector<T>& list){
    if (list.empty()){
        throw runtime_error ("Vectoren er tom");

    }

    T maxValue = list[0];
    for (int i = 1; i < list.size(); i++){
        if (list[i] > maxValue){
            maxValue = list[i];
        }

    }
    return maxValue;
};


int main (){
    vector<int> intVec {1, 5, 7, 3};
    cout << "Max værdien i vectoren for int er: " << max(intVec) << endl;

    vector<double> doubleVec {1.12, 1.21, 1.67, 1.68};
    cout << "Max værdien i vectoren for int er: " << max(doubleVec) << endl;

    vector<int> single = {42};
    cout << "Max (enkelt element): " << max(single) << endl;  // Forventer 42

    // Test med tom vector
    try {
        vector<int> empty = {};
        cout << max(empty) << endl;
    } catch (runtime_error& e) {
        cout << "Fejl fanget: " << e.what() << endl;  // Forventer fejlbeskeden
    }

    return 0;
}


