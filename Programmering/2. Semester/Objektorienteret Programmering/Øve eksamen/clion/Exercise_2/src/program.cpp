#include <iostream>
#include "cat_array.h"

int main() {

    cat_array array(2, 2);
    array.add("garfield", 2, 3);
    array.add("pussycat", 2, 3);
    array.add("lucifer", 2, 3);
    std::cout << array.get(2).to_string() << "\n";
}