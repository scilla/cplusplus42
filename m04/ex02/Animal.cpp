#include "Animal.hpp"

Animal::Animal()
{
	type = "Animal";
}

Animal::Animal(const Animal &animal) {
	*this = animal;
}

Animal &Animal::operator=(const Animal &animal) {
	type = animal.type;
	return *this;
}

Animal::~Animal()
{
}

void Animal::makeSound() const {
	std::cout << "I'm a animal. I may or may not make sounds." << std::endl;
}

std::string		Animal::getType() const {
	return type;
}

void	Animal::setType(std::string str) {
	type = str;
}
