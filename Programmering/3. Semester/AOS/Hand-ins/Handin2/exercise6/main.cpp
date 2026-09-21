#include "map.h"
#include <string>

int main() {
    Vector_map<std::string, int> ages;

    std::cout << "Test insert:\n";
    ages.insert("Alice", 30);
    ages.insert("Bob", 25);
    ages.insert("Charlie", 35);
    ages.print();

    std::cout << "\nTest insert update (same key):\n";
    ages.insert("Bob", 25); // should update, not duplicate
    ages.print();
    std::cout << "Size: " << ages.size() << " (expected 3)\n";

    std::cout << "\nTest find:\n";
    std::cout << "Alice: " << ages.find("Alice") << " (expected 30)\n";
    std::cout << "Bob: " << ages.find("Bob") << " (expected 26)\n";

    std::cout << "\nTest contains:\n";
    std::cout << "Contains Charlie? " << (ages.contains("Charlie") ? "yes" : "no") << "\n";
    std::cout << "Contains David? " << (ages.contains("David") ? "yes" : "no") << "\n";

    std::cout << "\nTest remove:\n";
    ages.remove("Alice");
    ages.print();
    std::cout << "Size: " << ages.size() << " (expected 2)\n";

    std::cout << "\nTest with different types: int & string:\n";
    Vector_map<int, std::string> idToName;
    idToName.insert(1, "one");
    idToName.insert(2, "two");
    idToName.insert(3, "three");
    idToName.print();

    return 0;
}