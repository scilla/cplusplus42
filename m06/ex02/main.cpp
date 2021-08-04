#include <iostream>
#include <stdlib.h>
#include "Base.hpp"

Base* generate(void) {
	srand (time(NULL));
	Base* ptr = NULL;

	switch (rand() % 3)
	{
	case 0:
		ptr = new A;
		std::cout << "Created: A" << std::endl;
		break;
	case 1:
		ptr = new B;
		std::cout << "Created: B" << std::endl;
		break;	
	default:
		ptr = new C;
		std::cout << "Created: C" << std::endl;
		break;
	}
	return ptr;
}

void identify(Base* p) {
	A* ptrA = dynamic_cast<A*>(p);
	B* ptrB = dynamic_cast<B*>(p);
	C* ptrC = dynamic_cast<C*>(p);
	if (ptrA)
		std::cout << "Pointer found: A" << std::endl;
	else if (ptrB)
		std::cout << "Pointer found: B" << std::endl;
	else if (ptrC)
		std::cout << "Pointer found: C" << std::endl;
	else
		std::cout << "ops" << std::endl;
}

void identify(Base& p) {
	try
	{
		A baseA = dynamic_cast<A&>(p);
		std::cout << "Reference found: A" << std::endl;
	}
	catch(const std::exception& e)
	{
		try
		{
			B baseB = dynamic_cast<B&>(p);
			std::cout << "Reference found: B" << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << "Reference found: C" << std::endl;
		}
	}
	
}

int main() {
	Base* ptr = generate();
	identify(ptr);
	identify(*ptr);
	return 0;
}