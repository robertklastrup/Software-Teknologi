#include <iostream>
#include <vector>
#include <algorithm>


enum Karakter{
    minus3 = -3,
    nul = 0,
    to = 2,
    fire = 4,
    syv = 7,
    ti = 10,
    tolv = 12
};


class Student{
    private:
        std::string name;
        int age;
        Karakter grade;
    public:
        Student(std::string n, int a, Karakter g);
        std::string getName();
        int getAge();
        Karakter getGrade();
};


class Kursus{
    private:
        std::string navn;
        int ects;
        int alder;
    public:
        Kursus(std::string n, int e, int a);
        void print();
        bool isValid() const;
};