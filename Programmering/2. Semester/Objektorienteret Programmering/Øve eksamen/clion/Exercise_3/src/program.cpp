#include <iostream>
#include "linked_list.h"

int main() {

    cat felix("felix", 1, 2);
    cat garfield("garfield", 1, 2);
    cat lucifer("lucifer", 1, 2);
    cat kitty("kitty", 1, 2);
    linked_list list;

    list.insert_front(felix);
    list.insert_front(garfield);
    list.insert_front(lucifer);
    list.insert_front(kitty);

    list.delete_front();

    std::cout << list.to_string() << "\n";
}