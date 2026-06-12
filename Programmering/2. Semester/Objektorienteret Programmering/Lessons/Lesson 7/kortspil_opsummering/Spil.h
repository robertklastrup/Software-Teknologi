#include <iostream>
#include <vector>
#include "Kort.h"
#include "Spiller.h"
#include "Haand.h"

class Spil{
    private:
        std::vector <Kort> deck_;
        Spiller spiller_;
        Spiller bot_;
    public:
        Spil();
        void delKort();
        void spillerBet();
        void visResultat();
        void startSpil();

};