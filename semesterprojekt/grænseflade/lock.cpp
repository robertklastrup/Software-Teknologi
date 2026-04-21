#include <iostream>
#include <vector>
#include "lock.h"
using namespace std;

 
    Lock :: Lock(){
        pin = "0";
        locked = true;
        nopin = false;
        isValid = false;
    }

    void Lock :: lockSystem(){
        locked = true;
    }

    void Lock :: unlockSystem (){
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

    void Lock :: checkStatus(){
        if(locked == false){
            cout << "Batteriet er ikke låst" << endl;
        }
        else{
            cout << "Batteriet er låst" << endl;
        }
    }

    void Lock :: pinIsValid(){
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

    void Lock :: createPin(){
        do{
            cout << "Opret en pinkode" << endl;
            cin >> pin;
            pinIsValid();
        } while (!isValid);
    }

/*
Max 3 forsøg med login til bruger eller pinkode 
De får tilsendt et bekræftelse på mail
*/
