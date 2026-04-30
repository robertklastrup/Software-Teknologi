#include <iostream>
#include "Counter.h"
using namespace std;
    
    Counter :: Counter(){
        count_ = count_ + 1;
    }
    int Counter :: get_count(){
        return (count_);
    }
    void Counter :: reset_count(){
        count_ = 0;
    }
