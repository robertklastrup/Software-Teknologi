#include "Fraction.h"

int main()
{
	//Opgave 1 c-1)
	Fraction f1;
	std::cout << f1.getNominator() << std::endl;
	std::cout << f1.getDenominator() << std::endl;

	//Opgave 1 c-2)
	try {
    	Fraction f2(1, 0);
	} catch (std::invalid_argument& e) {
    	std::cout << "Exception: " << e.what() << std::endl;
	}

	
	//Opgave 1 c-3)
	Fraction f3 (3, 2);
	Fraction f4 (9, 6);
	Fraction f5 (1, 2);

	if (f3 == f4){
		std::cout << "True" << std::endl;
	}
	else{
		std::cout << "False" << std::endl;
	}

	if (f3 == f5){
		std::cout << "True" << std::endl;
	}
	else{
		std::cout << "False" << std::endl;
	}
	
	//Opgave 1 e)
	Fraction f6 (2, 3);
	std::cout << f6 << std::endl;
	//Opgave 1 g)
	Fraction f7(1,2);
	Fraction f8(4,6);
	Fraction f9 = f7 + f8;
	std::cout << "Fraction 1: " << f7 << std::endl;
	std::cout << "Fraction 2: " << f8 << std::endl;
	std::cout << "Fractions added: " << f9 << std::endl;

	return 0;
}
