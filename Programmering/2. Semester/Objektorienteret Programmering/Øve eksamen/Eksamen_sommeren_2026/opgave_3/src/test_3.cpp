#include "test_3.h"
#include "cat.h"
#include "contains.h"
#include <vector>
#include <list>
#include <iostream>

void test_contains() {
    cat c1 ("Kat1", 12);
    cat c2 ("Kat2", 8);
    cat c3 ("Kat3", 9);

    std::list <cat> cats {c1,c2,c3};

    if(contains(cats, c1) == true){
        std::cout << "Fundet" << std::endl;
    }
    else{
        std::cout << "Ikke fundet" << std::endl;
    }

    std::list <cat> cats2 {c2,c3};
    if(contains(cats2, c1) == true){
        std::cout << "Fundet" << std::endl;
    }
    else{
        std::cout << "Ikke fundet" << std::endl;
    }

}
