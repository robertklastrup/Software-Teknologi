#include "opg1.h"


Studieopgave::Studieopgave(std::string t1, std::string f, double t2, Sværhedsgrad s){
    titel = t1;
    fag = f;
    tid = t2;
    sværhedsgrad = s;
}

std::string Studieopgave::getTitel (){
    return titel;
}
std::string Studieopgave::getFag (){
    return fag;
}
double Studieopgave::getTid (){
    return tid;
}
Sværhedsgrad Studieopgave::getSværhedsgrad (){
    return sværhedsgrad;
}

void Studieopgave::setTitel (std::string t){
    titel = t;
}
void Studieopgave::setFag (std::string f){
    fag = f;
}
void Studieopgave::setTid (double t){
    tid = t;
}
void Studieopgave::setSværhedsgrad (Sværhedsgrad s){
    sværhedsgrad = s;
}

void Studieopgave::print(){
    if (sværhedsgrad == 1){
        std::cout << "Titel: " << titel << " | Fag: " << fag << " | Tid: " << tid << " timer | Sværhedsgrad: Let";
    }
    else if(sværhedsgrad == 2){
        std::cout << "Titel: " << titel << " | Fag: " << fag << " | Tid: " << tid << " timer | Sværhedsgrad: Mellem";
    }
    else if (sværhedsgrad == 3){
        std::cout << "Titel: " << titel << " | Fag: " << fag << " | Tid: " << tid << " timer | Sværhedsgrad: Svær";
    }
}