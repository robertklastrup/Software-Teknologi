#include "Øvelser.h"



Student::Student(std::string n, int a, Karakter g){
    name = n;
    age = a;
    grade = g;
}
std::string Student::getName(){
    return name;
}
int Student::getAge(){
    return age;
}
Karakter Student::getGrade(){
    return grade;
}

Kursus::Kursus(std::string n, int e, int a){
    navn = n;
    ects = e;
    alder = a;
}
void Kursus::print(){
    std::cout << "Navn: " << navn << " | ECTS: " << ects << " | Alder: " << alder << std::endl;
}