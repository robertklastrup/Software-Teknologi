#include "test_string_writer.h"
#include <list>
#include <iostream>
#include "string_writer_template.h"
#include "person.h"

void test_template_as_string() {
    std::list<person> persons;

    person p1 ("Robert", 22);
    person p2 ("Kevin", 23);

    persons.push_back(p1);
    persons.push_back(p2);

    std::cout << as_string(persons.begin(), persons.end()) << std::endl;

}