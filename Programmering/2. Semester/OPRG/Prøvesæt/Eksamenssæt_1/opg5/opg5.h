#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

//opgave 3 klasse + enum og ændringer af grade fra double til Karakter

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
    public:
    std::string name;
    int age;
    Karakter grade;
    Student(std::string n, int a, Karakter g);
    bool isValid() const;
};

void gennemsnit(std::vector <Karakter> g, int n);
