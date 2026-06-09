#include <iostream>
#include <vector>

enum Sværhedsgrad{
    let = 1,
    mellem = 2,
    svaer = 3,
};

class Studieopgave{
    private:
        std::string titel;
        std::string fag;
        double tid;
        Sværhedsgrad sværhedsgrad;
    public:
        Studieopgave(std::string t1, std::string f, double t2, Sværhedsgrad s);

        std::string getTitel ();
        std::string getFag ();
        double getTid ();
        Sværhedsgrad getSværhedsgrad ();

        void setTitel (std::string t);
        void setFag (std::string f);
        void setTid (double t);
        void setSværhedsgrad (Sværhedsgrad s);

        void print();
};