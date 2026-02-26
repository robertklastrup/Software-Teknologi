#include    <iostream>
#include   <array>
#include   <string>
#include  <cmath>

using namespace std;


//multidimentional arrays er arrays der indeholder flere arrays

int main () 
{
    //første array er rækker, anden array er kolonner
    string cars[][3] = {{"Volvo", "BMW", "Ford" },
                        {"Toyota", "Honda", "Nissan" },
                        {"Audi", "Mercedes", "Volkswagen"}
    };

    //cout << cars[0][0] << endl; //Volvo, fordi det er første række og første kolonne i vores matrix/array
    //cout << cars[1][2] << endl; //Nissan, fordi det er anden række og tredje kolonne i vores matrix/array

    cout << cars[0][0] << " "; 
    cout << cars[0][1] << " "; 
    cout << cars[0][2] << endl; 
    cout << cars[1][0] << " "; 
    cout << cars[1][1] << " "; 
    cout << cars[1][2] << endl; 
    cout << cars[2][0] << " "; 
    cout << cars[2][1] << " "; 
    cout << cars[2][2] << endl; 

    //Her har jeg altså skrevet hele matricen op, hvor jeg først ender line efter at hver række har været igennem
    return 0;
}