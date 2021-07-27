#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main( void ) {
	Point a(Fixed(5), Fixed(0));
	Point b(Fixed(18), Fixed(13));
	Point c(Fixed(1), Fixed(13));
	Point p;
	int res;

	for (int y = 14; y >= 0; y--) {
		p.setY(Fixed(y));
		for (int x = 0; x < 20; x++) {
			p.setX(Fixed(x));
			res = bsp(a, b, c, p);
			if (!res)
				std::cout << "\033[31m";
			else
				std::cout << "\033[1;32m";
			std::cout << res << "\033[0m ";
		}
		std::cout << std::endl;
	}
	return 0;
}