#include "Spiller.h"




Spiller :: Spiller(std::string navn){
    navn_ = navn;
    saldo_ = 1000;
}
void Spiller :: bet(int beloeb){
    saldo_ = saldo_ - beloeb;
}
void Spiller :: modtagKort(Kort k){
    haand_.tilfoejKort(k);

}
Haand Spiller :: getHaand(){
    return haand_;
}
std::ostream& operator<<(std::ostream& os, const Spiller& s){
    os << s.navn_ << '\n' << "Saldo: " << s.saldo_ << '\n' << s.haand_ << '\n';
    return os;
}
