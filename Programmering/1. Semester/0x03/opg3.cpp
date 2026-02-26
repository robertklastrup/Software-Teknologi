#include    <iostream>
using namespace std;
#include <cstdlib>   // for rand() og srand()
#include <ctime>     // for time()


int main() {
    
    int velbefindende (0-100);

    cout<<"indtast din alder: ";
    int alder;
    if(alder<0){
        int velbefindende=20;
    }
    
    cout<<"indtast antal timer du sover om natten: ";
    int timer;
    cin >> velbefindende;   
    if(timer=7<=9){
        int velbefindende=20;
    } 
    else if (timer=6){
        int velbefindende=15;
    }
    else if (timer=5){
        int velbefindende=10;
    }
    else if (timer=4){
        int velbefindende=5;
    }
    else if (timer=10){
        int velbefindende=15;
    }
    else if (timer=11){
        int velbefindende=10;
    }
    else if (timer=12){
        int velbefindende=5;
    }
    else {
        int velbefindende=0;
    }
    
    cout<<"indtast antal studietimer om dagen";
    int studietimer;
    cin >> velbefindende;
    if(studietimer=1<=2){
        int velbefindende=15;
    }
    else if(studietimer=3<=6){
        int velbefindende=20;
    }
    else if(studietimer=0){
        int velbefindende=0;
    }
    else{
        int velbefindende=10;}

    cout<<"indtast stress niveau (1-10): ";
    int stress;
    cin >> stress;
    if(stress=1<=3){
        int velbefindende=20;
    }
    else if(stress=4<=6){
        int velbefindende=15;
    }
    else if(stress=7<=8){
        int velbefindende=10;
    }
    else if(stress=9<=10){
        int velbefindende=0;   
    }
    else{
         cout << "Ugyldigt valg" << endl;
    }
        

     cout<<"indtast antal timer du har trænet: ";
     int træning;
     cin >> træning;   
     if(træning=1<=2){
        int velbefindende=15;
    }
    else if (træning=3<=5){
        int velbefindende=20;
    }
    else if (træning=6<=8){
        int velbefindende=15;
    }
    else if (træning=0){
        int velbefindende=0;
    }
    else{
        int velbefindende=5;
    }

    cout<<"dit velbefindende er: "<<velbefindende<<endl;
    
    return 0;
}