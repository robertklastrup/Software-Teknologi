#include    <iostream>
using namespace std;


// Et nested loop er et loop inde i et andet loop.

//Vi laver et program der tæller til 10, 3 gange:
int main() {
    
    
    for(int i = 1; i <= 3; i++){
        for(int i = 1; i <= 10; i++){
        cout << i << " ";
        }
    }
    cout << '\n';

    return 0;
}