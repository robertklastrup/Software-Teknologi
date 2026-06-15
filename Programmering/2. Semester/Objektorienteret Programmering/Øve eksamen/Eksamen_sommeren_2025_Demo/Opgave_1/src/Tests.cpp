#include "Tests.h"
#include "Vector3D.h"
#include <iostream>

// Opgave b-2)	
void test_to_string()
{
    vector_3d v (1,2,3);
    std::cout << v.to_string();
}

// Opgave c-2)	
void test_additive_inverse_operator()
{
	vector_3d v1 (1,2,3);
    vector_3d v2 = v1.operator!();
    std::cout << v2.to_string();
}

//Opgave d-3)
void test_addition_operator()
{
	vector_3d v_1 (2,4,6);
    vector_3d v_2 (4,4,4);
    vector_3d v_3 = v_1 + v_2;
    std::cout << v_3.to_string();
}

//Opgave e-3)
void test_subtraction_operator()
{
    vector_3d v_1 (2,4,6);
    vector_3d v_2 (4,4,4);
    vector_3d v_3 = v_1 - v_2;
    std::cout << v_3.to_string();
}
