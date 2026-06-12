#include <iostream>
using namespace std;

// template-klasse Rob med to værdier af vilkårlig type:
template <class T>
class Rob{
    T first;
    T second;
    public:
        // sætter first og second:
        Rob(T a, T b){
            first = a;
            second = b;
        }
        T bigger ();
};

// returnerer den største af first og second:
template <class T>
T Rob <T> :: bigger () {
    return (first>second?first:second);
}

int main () {
    // opretter Rob med int og printer det største tal:
    Rob <int> ro (69, 420);
    cout << "Det største tal er: " << ro.bigger() << endl;
}
