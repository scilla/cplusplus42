#include <iostream>
#include "Data.hpp"

int main() {
	Data* ptr = new Data;
	uintptr_t serialized = serialize(ptr);
	Data* new_ptr = deserialize(serialized);

	std::cout << ptr << std::endl;
	std::cout << serialized << std::endl;
	std::cout << new_ptr << std::endl;
}