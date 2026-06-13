#include "StringProcessor.h"
#include "RemoveChar.h"
#include "ToLowerCase.h"
#include "ToUpperCase.h"
#include "Document.h"

int main()
{
	// Opgave 3 h)
	

	ToUpperCase* u = new ToUpperCase();
	ToLowerCase* l = new ToLowerCase();
	RemoveChar* r = new RemoveChar('e');

	Document d1("My First Test");
	Document d2("My Second Test");

	d1.add(r);
	d1.add(u);
	d1.process();

	d2.add(r);
	d2.add(l);
	d2.process();

	std::cout << d1 << std::endl;
	std::cout << d2 << std::endl;
	
	return 0;
}
