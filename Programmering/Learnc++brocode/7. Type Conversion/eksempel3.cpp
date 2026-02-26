#include    <iostream>
using namespace std;


// dette eksempell gå ud på hvis man har en online eksamen og man skal give det en score:
int main() {

   int correct = 8;
   int questions = 10;

   double score = correct / (double)questions * 100;
   // Her konverterer vi correct til en double for at få decimaler med i division

    cout << "Din score er: " << score << "%" << '\n';

    return 0;
}