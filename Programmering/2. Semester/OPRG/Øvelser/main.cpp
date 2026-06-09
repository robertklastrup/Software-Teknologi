#include "Øvelser.h"


int main(){
    Student s1("Robert", 22, syv);
    Student s2("Anna", 20, tolv);

    std::cout << s1.getName() << std::endl;
    std::cout << s1.getAge() << std::endl;
    std::cout << s2.getName() << std::endl;
    std::cout << s2.getGrade() << std::endl;
}