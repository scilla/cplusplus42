#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main( void ) {
	Point a(Fixed(0), Fixed(0));
	Point b(Fixed(3), Fixed(0));
	Point c(Fixed(0), Fixed(3));
	Point p(Fixed(1), Fixed(1));


	std::cout << a.getX() << a.getY() << std::endl;
	std::cout << b.getX() << b.getY() << std::endl;
	std::cout << c.getX() << c.getY() << std::endl;

	std::cout << bsp(a, b, c, p) << std::endl;
	return 0;
}