#include <iostream>
#include "linked_list.h"

int main() {

    cat felix("felix", 1, 2);
    cat garfield("garfield", 1, 2);
    cat lucifer("lucifer", 1, 2);
    cat kitty("kitty", 1, 2);
    cat pussycat("pussycat", 1, 2);
    linked_list list;
    list.insert_front(felix);
    list.insert_front(garfield);
    list.insert_end(lucifer);
    std::cout << list.to_string() << "\n";

    std::cout << list.get_front()->to_string() << "\n";
    std::cout << list.get_end()->to_string() << "\n" << "\n";

    std::cout << list.get(1)->get_data()->to_string() << "\n" << "\n";

    std::cout << list.size() << "\n" << "\n";


    list.insert_after(pussycat, list.get(1));
    std::cout << list.to_string() << "\n";


}