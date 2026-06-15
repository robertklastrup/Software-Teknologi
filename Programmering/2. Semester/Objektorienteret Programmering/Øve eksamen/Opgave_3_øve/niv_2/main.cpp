#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "DomesticAnimal.h"
#include <iostream>
#include <vector>



int main (){
    Dog d ("Rex");
    std::cout << d.describe() << std::endl;
    std::cout << d.sound() << std::endl;


    Cat c ("Whiskers");
    std::cout << c.describe() << std::endl;
    std::cout << c.sound() << std::endl;

    std::vector<Animal*> Animals = {&d, &c};
    for (int i = 0; i < Animals.size(); i++){
        std::cout << Animals[i]->describe() << std::endl;
        std::cout << Animals[i]->sound() << std::endl;
        std::cout << std::endl;
    }

}