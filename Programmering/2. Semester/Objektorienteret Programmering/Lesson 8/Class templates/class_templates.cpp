#include <iostream>
using namespace std;

template <class T>
class Rob{
    T first; 
    T second;
    public:
        //constructer
        Rob(T a, T b){
            first = a;
            second = b;
        }
        T bigger ();
};

template <class T>
T Rob <T> :: bigger () {
    return (first>second?first:second);
}

int main () {
    Rob <int> ro (69, 420);
    cout << "Det største tal er: " << ro.bigger() << endl;
}