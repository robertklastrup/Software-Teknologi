#include <iostream>
#include "address.h"

int main() {

    address a;
    a.set_street("Elm Street")
            .set_number(13)
            .set_floor(1)
            .set_zip_code("666")
            .set_city("Sin City")
            .set_country("The Waste Lands");
    std::cout << a.to_string();

}