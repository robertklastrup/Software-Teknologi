#include <iostream>
#include <string>

using namespace std;


void input(double& distance, double& fart) {
    cout << "Indtast distance i km: "<< '\n';
    cin >> distance;

    cout << "Indtast fart i km/t: ";
    cin >> fart;
}
    
double beregnTid(double distance, double fart) {
    return distance / fart;
}


double beregnKalorie(double distance) {
    return distance * 50; // Antager 50 kalorier pr. km
}

void output(double tid, double kalorier) {
    cout << "Tid: " << tid << " timer" << endl;
    cout << "Kalorier forbrændt: " << kalorier << " kcal" << endl;
}

int main() {
    double distance, fart;
    input(distance, fart);
    
    double tid = beregnTid(distance, fart);
    double kalorier = beregnKalorie(distance);
    
    output(tid, kalorier);
    
    return 0;
}
