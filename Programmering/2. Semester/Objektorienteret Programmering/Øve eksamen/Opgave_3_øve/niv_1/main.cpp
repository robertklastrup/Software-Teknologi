#include "Circle.h"
#include "Shape.h"
#include "Rectangle.h"
#include <iostream>
#include <vector>


int main (){
    Circle c (5);
    std::cout << c.describe() << std::endl;
    std::cout << c.area()<< std::endl;

    Rectangle r (3, 4);
    std::cout << r.describe()<< std::endl;
    std::cout << r.area()<< std::endl;
    
    std::vector <Shape*> shape {&c, &r};
    
    for (int i = 0; i < shape.size(); i++){
        std::cout << shape[i]->describe() << std::endl;
    }

}