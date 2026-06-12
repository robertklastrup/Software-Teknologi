#include "Haand.h"
#include "Kort.h"

Haand::Haand() {}

void Haand::tilfoejKort(Kort k) {
    kort_.push_back(k);
}

std::ostream& operator<<(std::ostream& os, const Haand& h) {
    
    for (int i = 0; i < h.kort_.size(); i++){
        os << h.kort_[i];
    }
    return os;
}

bool operator>(const Haand& h1, const Haand& h2) {
    
    int maxvaerdi1 = 0;
    int maxvaerdi2 = 0;
    for (int i = 0; i < h1.kort_.size(); i++){
        h1.kort_[i].getVaerdi();
        if (maxvaerdi1 < h1.kort_[i].getVaerdi()){
            maxvaerdi1 = h1.kort_[i].getVaerdi();
        }
    }
    for (int i = 0; i < h2.kort_.size(); i++){
        if (maxvaerdi2 < h2.kort_[i].getVaerdi()){
            maxvaerdi2 = h2.kort_[i].getVaerdi();
        }
    }
    return maxvaerdi1 > maxvaerdi2;
    
}