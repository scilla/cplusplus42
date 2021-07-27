#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed k(0.0f);
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed const l( Fixed( 5.0f ) / Fixed( 2 ) );

	std::cout << k << std::endl;
	std::cout << l << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;
	
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}