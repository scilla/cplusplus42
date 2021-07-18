#include <vector>
#include <iostream>

int main(void) {
	int	const				amounts[]	= { 42, 54, 957, 432, 1234, 0, 754, 16576 };
	size_t const			amounts_size( sizeof(amounts) / sizeof(int) );

	std::cout << *(amounts + amounts_size) << std::endl;

	return 0;
}