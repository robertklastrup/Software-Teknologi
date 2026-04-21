#include <iostream>
#include <vector>
using namespace std;


class Lock{
    public:
        string pin;
        bool nopin;
        bool isValid;
        bool locked;
    Lock();
    void lockSystem();
    void unlockSystem();
    void checkStatus();
    void pinIsValid();
    void createPin();
};

        