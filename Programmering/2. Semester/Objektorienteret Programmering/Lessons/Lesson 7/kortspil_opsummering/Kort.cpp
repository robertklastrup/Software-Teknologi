#include "Kort.h"



Kort::Kort(int v, Kulør k){
    vaerdi_ = v;
    kul_ = k;
}

std::ostream& operator<<(std::ostream& os, const Kort& k1){
    switch(k1.kul_){
        case HJERTER: os << "Hjerter"; break;
        case RUDER: os << "Ruder"; break;
        case KLOER: os << "Kloer"; break;
        case SPAR: os << "Spar"; break;
    }
    switch(k1.vaerdi_){
        case 11: os << " Knaegt" << '\n'; break;
        case 12: os << " Dronning" << '\n'; break;
        case 13: os << " Konge" << '\n'; break;
        case 14: os << " Es" << '\n'; break;
        default: os << " " << k1.vaerdi_ << '\n';
    }

    return os;
}

bool operator==(Kort k1, Kort k2){
    if(k1.vaerdi_ == k2.vaerdi_ && k1.kul_ == k2.kul_){
        return true;
    }
    else{
        return false;
    }
}

int Kort:: getVaerdi() const{
            return vaerdi_;
        }