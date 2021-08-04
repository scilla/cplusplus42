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
		break;
	case 1:
		ptr = new B;
		break;	
	default:
		ptr = new C;
		break;
	}
	return ptr;
}

void identify(Base* p) {
	A* ptrA = dynamic_cast<A*>(p);
	B* ptrB = dynamic_cast<B*>(p);
	C* ptrC = dynamic_cast<C*>(p);
	if (ptrA)
		std::cout << "A" << std::endl;
	else if (ptrB)
		std::cout << "B" << std::endl;
	else if (ptrC)
		std::cout << "C" << std::endl;
	else
		std::cout << "ops" << std::endl;
}

void identify(Base& p) {
	try
	{
		A baseA = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch(const std::exception& e)
	{
		try
		{
			B baseB = dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << "C" << std::endl;
		}
	}
	
}

int main() {
	Base* ptr = generate();
	identify(ptr);
	identify(*ptr);
	return 0;
}