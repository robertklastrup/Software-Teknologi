#include "Currency.h"
#include "Amount.h"
#include <iostream>

int main()
{
	//Opgave 1 a)
	Currency c1 ("Dollar", 0.92);

	std::cout << c1.fromStandardCurrency(460) << std::endl;
	std::cout << c1.toStandardCurrency(460) << std::endl;
	//Opgave 1 e)
	Currency c2 ("Dollar", 0.92);
	Amount a1 (120, c2);

	std::cout << a1.toString() << std::endl;

	//Opgave 1 g)
	Currency c3 ("Dollar", 0.92);
	Currency c4 ("Pound", 1.18);

	Amount a2 (1000, c3);
	Amount a3 (1000, c4);

	Amount a4 = a2 + a3;
	std::cout << a4.toString() << std::endl;



	//Opgave 1 i)
	Currency dollar ("Dollar", 0.92);
	Currency pound ("Pound", 1.18);

	Amount a5 (500, dollar);
	Amount a6 (389.83, pound);

	if (a5 == a6){
		std::cout << "Sandt" << std::endl;
	}
	else{
		std::cout << "Falsk" << std::endl;
	}
	

	return 0;
}
