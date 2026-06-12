#include <iostream>
#include "Counter.h"
using namespace std;

// konstruktør: tæller op ved oprettelse:
Counter :: Counter(){
    count_ = count_ + 1;
}

// returnerer nuværende tællerværdi:
int Counter :: get_count(){
    return (count_);
}

// nulstiller tæller til 0:
void Counter :: reset_count(){
    count_ = 0;
}
