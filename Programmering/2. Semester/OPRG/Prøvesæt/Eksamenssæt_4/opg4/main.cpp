#include "opg4.h"


int main (){
    Ansat a1 ("Jens", 50000, 2, "Software");
    Ansat a2 ("Jens", 70000, 2, "Software");
    Ansat a3 ("Jens", 45000, 2, "Software");
    Ansat a4 ("Jens", 13000, 1, "Software");
    Ansat a5 ("Jens", 90000, 2, "Software");

    std::cout << gennemsnit({a1,a2,a3,a4,a5}, 2) << std::endl;
}