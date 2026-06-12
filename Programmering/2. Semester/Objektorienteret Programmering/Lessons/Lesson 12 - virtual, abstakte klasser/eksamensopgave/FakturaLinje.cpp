#include "FakturaLinje.h"

FakturaLinje::FakturaLinje(std::string navn, double enhedsPris, double antal){
    navn_ = navn;
    enhedsPris_ = enhedsPris;
    antal_ = antal;
}

void FakturaLinje::print(){
    std::cout << navn_ << " " << antal_ << " enheder til "  << enhedsPris_ << " kr. i alt " << beregnPris() << std::endl;
}
FakturaLinje::~FakturaLinje(){}
