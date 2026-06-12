#include <iostream>
#pragma once

enum Kulør {
    HJERTER,  // = 0
    RUDER,    // = 1
    KLOER,    // = 2
    SPAR      // = 3
};


class Kort{
    private:
        int vaerdi_;
        Kulør kul_;
    public:
        Kort(int v, Kulør k);
        friend std::ostream& operator<<(std::ostream& os, const Kort& k1);
        friend bool operator==(Kort k1, Kort k2);
        int getVaerdi() const;




};