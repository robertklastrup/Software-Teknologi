#include "Service.h"



Service::Service(std::string navn, double enhedsPris, double antal, bool momsPligtig) : FakturaLinje(navn, enhedsPris, antal), momsPligtig_(momsPligtig){}
double Service::beregnPris(){
    if (momsPligtig_ == true){
        return(enhedsPris_ * antal_ * 1.25);
    }
    else{
        return (enhedsPris_ * antal_);
    }
}
void Service::print(){
    if (momsPligtig_ == true){
        FakturaLinje::print();
        std::cout << "Momspligtig" << std::endl;
    }
    else{
        FakturaLinje::print();
        std::cout << "Ikke momspligtig" << std::endl;
    }
}