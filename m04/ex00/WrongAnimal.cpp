#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal &animal) {
	*this = animal;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &animal) {
	type = animal.type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
}

void WrongAnimal::makeSound() const {
	std::cout << "I'm a WrongAnimal. Please kill me." << std::endl;
}

std::string		WrongAnimal::getType() const {
	return type;
}