#include <iostream>
#include <vector>
using namespace std;

bool exists (vector<int> data, int exists);



class person {
    private:
        int ssn;
        string name;
    public:

        friend bool operator == (const person& other) const;
};