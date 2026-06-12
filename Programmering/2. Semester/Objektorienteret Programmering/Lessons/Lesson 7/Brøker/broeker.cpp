#include "broeker.h"



Broek :: Broek(int t, int n){
    if (n == 0){
        throw std::invalid_argument("Brøk er 0");
    }
    else{
        taeller_ = t;
        naevner_ = n;
    }
}
Broek operator+(Broek b1, Broek b2){
    return Broek((b1.taeller_ * b2.naevner_ + b1.naevner_ * b2.taeller_),(b1.naevner_ * b2.naevner_));
}
Broek operator*(Broek b1, Broek b2){
    return Broek ((b1.taeller_ * b2.taeller_),(b1.naevner_ * b2.naevner_));
}
bool operator==(Broek b1, Broek b2){
    if (b1.taeller_ == b2.taeller_ && b1.naevner_== b2.naevner_){
        return true;
    }
    else{return false;}
}
std::ostream& operator<<(std::ostream& os, const Broek& b1){
    os << b1.taeller_ << "/" << b1.naevner_ << '\n';
    return os;
}