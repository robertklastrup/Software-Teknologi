#include "Spil.h"
#include <algorithm>
#include <random>

Spil::Spil() : spiller_ ("Robert"), bot_ ("Bot1"){
    for(int vaerdi = 2; vaerdi <= 14; vaerdi++){
        deck_.push_back(Kort(vaerdi, HJERTER));
    }
    for(int vaerdi = 2; vaerdi <= 14; vaerdi++){
        deck_.push_back(Kort(vaerdi, RUDER));
    }
    for(int vaerdi = 2; vaerdi <= 14; vaerdi++){
        deck_.push_back(Kort(vaerdi, KLOER));
    }
    for(int vaerdi = 2; vaerdi <= 14; vaerdi++){
        deck_.push_back(Kort(vaerdi, SPAR));
    }
    std::shuffle(deck_.begin(), deck_.end(), std::default_random_engine(std::random_device{}()));
}
void Spil :: delKort(){
    for(int i = 0; i < 5; i++){
        spiller_.modtagKort(deck_[0]);
        deck_.erase(deck_.begin());
    }
    for(int i = 0; i < 5; i++){
        bot_.modtagKort(deck_[0]);
        deck_.erase(deck_.begin());
    }
}
void Spil :: spillerBet(){
    std::cout << spiller_.saldo_ << '\n';
    std::cout << "Vil du bette? (Minimum 50) eller fold" << '\n';

}
void Spil :: visResultat();
void Spil :: startSpil();

