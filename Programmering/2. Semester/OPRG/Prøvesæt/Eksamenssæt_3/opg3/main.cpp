#include "opg3.h"


int main(){
    SensorMåling s1 ("33:59:42", 5.0, "OK");

    std::cout << s1.isValid() << std::endl;
    s1.makeValid();

}