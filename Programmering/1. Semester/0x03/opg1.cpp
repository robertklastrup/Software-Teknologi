#include  <iostream>
using namespace std;

int main() {

    int num;
    
    cout << "Indtast et tal: ";
    cin >>num;
    for(int i=1;i<=num;i++){
        int newNum=i*i;
        cout<<i<<"  "<< newNum << endl;

    }
    return 0;
}
