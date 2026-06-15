#include "test_container_template.h"
#include "container_template.h"
#include <iostream>
#include "person.h"

void test_template_to_string_person() {
    person p1("Rob", 22);
    person p2("Kevin", 23);

    container_template<person> c;
    c.add(p1);
    c.add(p2);

    std::cout << c.to_string() << std::endl;

}

void test_template_to_string_sorted_person() {
    person p1("Anders", 50);
    person p2("Rob", 22);
    person p3("Kevin", 23);

    container_template<person> c;
    c.add(p1);
    c.add(p2);
    c.add(p3);

    std::cout << c.to_string_sorted() << std::endl;
}
