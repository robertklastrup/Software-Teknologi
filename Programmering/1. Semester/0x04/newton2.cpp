#include <iostream>
using namespace std;

double readPositiveDouble()
{
    double x;
    cout << "Indtast et positivt tal: ";
    cin >> x;
    return x;
}

void sqrtNewton(double x)
{
    double g = x;
    double epsilon = 1e-6;
    int maxIter = 100;
    int iter = 0;

    cout << "Starter iteration..." << endl;

    while (iter < maxIter) {
        double ny = 0.5 * (g + x / g);

        cout << "iteration" << iter
            << ": g = " << g
            << ", ny = " << ny << endl;

        if (abs(ny-g) < epsilon) {
            cout << "beregnet kvadratrod: " << ny << endl;
            break;
        }    

        g = ny;
        iter++;
    }
}

void printResult()
{
    cout << "Færdig!" << endl;
}

int main() {
    double x = readPositiveDouble();
    sqrtNewton(x);
    printResult();
    return 0;
}   