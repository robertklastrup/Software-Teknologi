#include    <iostream>
using namespace std;    
#include <cstdlib>   // for rand() og srand()
#include <ctime>     // for time()


int main() {
    
    int skade;

    cout << "Indtast styrke (1-10): ";
    int styrke;
    cin >> styrke;

    cout<<"indtast våbenskade (1=sværd, 2=økse, 3=bue): ";
    cin >> skade;
    int våbenskade;

    if (skade == 1) {
        int våbenskade = 10;
        cout << "Du har valgt sværd, du får 10 i skade" << endl;
    } else if (skade == 2) {
        int våbenskade = 15;
        cout << "Du har valgt økse, du får 15 i skade" << endl;
    } else if (skade == 3) {
        int våbenskade = 8;
        cout << "Du har valgt bue, du får 8 i skade" << endl;
    } else {
        cout << "Ugyldigt valg" << endl;
    }
    int crit;
     
     crit=(rand() % 10) ;
     if(crit>5){
        skade=(våbenskade+styrke)*2;
        cout<<crit<<endl;
    }

        if(crit<5){
        skade=(våbenskade+styrke);
        cout<<crit<<endl;
    }

     return 0;
     
     }
   


    
