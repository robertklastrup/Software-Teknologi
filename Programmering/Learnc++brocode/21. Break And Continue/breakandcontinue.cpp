#include    <iostream>
using namespace std;


// break = break out of loop or switch statement
// continue = skip current iteration of loop


int main() {


    //Hvis vi bruger break herunder, så stopper loopet helt når i er 13.
    //Hvis vi bruger continue, så springer den bare 13 over og fortsætter til 14 osv.
    for(int i = 1; i <= 20; i++){
        if(i == 13){
            //break;
            continue;
        }
        cout << i << '\n';
    }

    return 0;
}