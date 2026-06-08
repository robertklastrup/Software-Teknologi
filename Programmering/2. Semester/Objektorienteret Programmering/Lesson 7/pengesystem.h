#include <iostream>
#include <vector>
using namespace std;




class Penge{
    private:
        int kroner_;
        int oere_;
    public:
        Penge(int k, int o);
        Penge operator+(Penge other);
        bool operator==(Penge other);
};
