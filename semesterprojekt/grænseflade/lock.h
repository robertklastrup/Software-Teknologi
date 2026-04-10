#include <iostream>
#include <vector>
using namespace std;


class Lock{
    public:
        int pin;
        vector <Lock> pins;
        bool locked = false;
    Lock(int p);
    void checkStatus();
    void createPin();
};
