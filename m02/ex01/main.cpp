#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	/*
	Fixed a;
	Fixed b( a );
	Fixed c;

	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	*/
	float	p;
	p = 1;
	Fixed k(p);
	p = 2;
	Fixed l(p);
	p = 4;
	Fixed m(p);
	p = 8;
	Fixed n(p);
	return 0;
}