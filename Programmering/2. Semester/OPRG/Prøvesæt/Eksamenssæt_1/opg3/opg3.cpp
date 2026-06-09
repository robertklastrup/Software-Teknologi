#include "opg3.h"


Student::Student(std::string n, int a, double g){
    name = n;
    age = a;
    grade = g;
}
bool Student::isValid() const {
    if ((age > 0) && (grade >= -3.0) && (grade <= 12.0)){
        std::cout << "Objektet er for eleven "<< name << " er gyldigt" << std::endl;
        return true;
    }
    else{
        std::cout << "Objektet er for eleven "<< name << " er ugyldigt" << std::endl;
        return false;
    }
}

    