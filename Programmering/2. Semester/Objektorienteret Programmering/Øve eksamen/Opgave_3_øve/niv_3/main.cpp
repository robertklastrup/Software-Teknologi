#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "DomesticAnimal.h"
#include "Zoo.h"
#include <iostream>
#include <vector>

int main (){
    Zoo zoo;
    Dog d ("Rex");
    Cat c ("Whiskers");

    zoo.add(&d);
    zoo.add(&c);

    std::cout << zoo.count() << std::endl;
    std::cout << zoo.describe_all() << std::endl;

}