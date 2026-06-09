#include <iostream>
#include <string>


class Student{
    public:
    std::string name;
    int age;
    double grade;
    Student(std::string n, int a, double g);
    bool isValid() const;
};