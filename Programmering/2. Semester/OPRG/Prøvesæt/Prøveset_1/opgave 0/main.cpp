#include "opgave0.h"
using namespace std;





int main (){
    vector<int> result = studieeffektiveTal(6, 12);

    for (int i = 0; i < result.size(); i++){
        cout << result[i] << endl;
    }
}