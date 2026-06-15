#include "Tests.h"
#include "point.h"
#include "Rotation.h"
#include "Translation.h"
#include "Combiner.h"
#include <cmath>
#include <iostream>

//Used to represent PI
const double pi = acos(-1);

//Opgave c-2)
void test_rotation()
{
    rotation r (pi/2);
    point p (1,1);

    point p1 = r.transform(p);
    std::cout << p1 << std::endl;
    

    
}    

//Opgave e-2)
void test_translation()
{
    translation t (2, 3);
    point p (1,1);

    point p1 = t.transform(p);
    std::cout << p1 << std::endl;
	
}

//Opgave g-2)
void test_combiner()
{
    rotation r (pi/2);
    translation t (4, 6);

    combiner c;
    c.add(&r);
    c.add(&t);

    point p (3,6);

    point p2 = c.transform(p);
    std::cout << p2 << std::endl;

}


