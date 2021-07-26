#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"
#include <unistd.h>

int main( void ) {
	Point a(Fixed(1), Fixed(1));
	Point b(Fixed(8), Fixed(1));
	Point c(Fixed(1), Fixed(8));
	Point p;

	for (int y = 0; y < 10; y++) {
		p.setY(Fixed(y));
		for (int x = 0; x < 10; x++) {
			p.setX(Fixed(x));
			std::cout << bsp(a, b, c, p);
		}
		std::cout << std::endl;
	}

	return 0;
}