#ifndef MAIN_CPP
#define MAIN_CPP
#include "whatever.hpp"
#include <iostream>

int main() {
	int a = 10;
	int b = 20;
	std::string c = "zuzzurellone";
	std::string d = "abaco";

	std::cout << "min between " << a << " and " << b << ": " << min(a, b) << std::endl;
	std::cout << "min between " << c << " and " << d << ": " << min(c, d) << std::endl;
	std::cout << "max between " << a << " and " << b << ": " << max(a, b) << std::endl;
	std::cout << "max between " << c << " and " << d << ": " << max(c, d) << std::endl;
	swap(a, b);
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	swap(c, d);
	std::cout << "c: " << c << std::endl;
	std::cout << "d: " << d << std::endl;
	return 0;
}


#endif /* MAIN_CPP */
