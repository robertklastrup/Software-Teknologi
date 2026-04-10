#include <iostream>
#include <vector>
using namespace std;


class Lock{
    public:
        string pin;
        bool nopin;
        bool isValid;
        bool locked;
    Lock(){
        pin = "0";
        locked = true;
        nopin = false;
        isValid = false;
    }
    void lockSystem(){
        locked = true;
    }
    void unlockSystem (){
        string p;
        
        do{
            cout << "Indtast pinkode" << endl;
            cin >> p;
            if(p == pin){
                locked = false;
                cout << "Låsen er nu låst op" << endl;
                return;
            }
            else{
                cout << "Forkert pin, prøv igen" << endl;
                locked = true;
            }
        } while (locked == true);
    }

    void checkStatus(){
        if(locked == false){
            cout << "Batteriet er ikke låst" << endl;
        }
        else{
            cout << "Batteriet er låst" << endl;
        }
    }
    void pinIsValid(){
        if (pin.length() != 4) {
            cout << "Pinkoden skal være 4 cifre!" << endl;
            isValid = false;
            return;
        }
        
        for (int i = 0; i < pin.length(); i++){
            if (!isdigit(pin[i])){
                cout << "Pinkoden skal være tal - prøv igen" << endl;
                isValid = false;
                return;
            }
            else if (isdigit(pin[i])){
                isValid = true;
            }
        }
        return;
    }
    void createPin(){
        do{
            cout << "Opret en pinkode" << endl;
            cin >> pin;
            pinIsValid();
        } while (!isValid);
    }

    
};