#include        <iostream>
using namespace std;

// type conversion = konvertering af en datatype til en anden datatype
//               implicit = automatisk konvertering af en datatype til en anden datatype
//               explicit = manuelt konvertering af en datatype til en anden datatype ved hjælp af casting



int main() {

    double x = (int) 3.14;
    // Her konverterer vi double værdien 3.14 til en int ved hjælp af explicit casting, derfor får vi 3 da int er hele tal
    cout << x;

    return 0;



}