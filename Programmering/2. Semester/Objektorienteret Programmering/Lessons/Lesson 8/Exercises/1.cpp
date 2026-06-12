#include <iostream>
#include <vector>
using namespace std;

// template-funktion der finder max-element i en vector:
template <class T>
T max (vector<T>& list){
    // kaster fejl hvis vectoren er tom:
    if (list.empty()){
        throw std::out_of_range ("Vectoren er tom");
    }
    T maxValue = list[0];
    // løber vector igennem og opdaterer maxValue hvis større element findes:
    for (int i = 1; i < list.size(); i++){
        if (list[i] > maxValue){
            maxValue = list[i];
        }
    }
    return maxValue;
};


int main (){
    // tester max med int-vector:
    vector<int> intVec {1, 5, 7, 3};
    cout << "Max værdien i vectoren for int er: " << max(intVec) << endl;

    // tester max med double-vector:
    vector<double> doubleVec {1.12, 1.21, 1.67, 1.68};
    cout << "Max værdien i vectoren for int er: " << max(doubleVec) << endl;

    // tester max med enkelt element:
    vector<int> single = {42};
    cout << "Max (enkelt element): " << max(single) << endl;

    // tester max med tom vector — forventer runtime_error:
    try {
        vector<int> empty = {};
        cout << max(empty) << endl;
    } catch (runtime_error& e) {
        cout << "Fejl fanget: " << e.what() << endl;
    }

    return 0;
}


