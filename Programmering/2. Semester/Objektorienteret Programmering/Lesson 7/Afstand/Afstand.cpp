#include "Afstand.h"

Afstand::Afstand(double m){
    meter_ = m;
}
Afstand operator+(Afstand a, Afstand b){
    return Afstand (a.meter_ + b.meter_);
}
bool operator<(Afstand a, Afstand b){
    if (a.meter_ < b.meter_){
        return true;
    }
    else{return false;}
}
std::ostream& operator<<(std::ostream& os, const Afstand& meter_){
    os << meter_.meter_ << " meter" << std::endl;
    return os;
}