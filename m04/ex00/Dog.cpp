#include "Dog.hpp"

Dog::Dog() {
	setType("Dog");
}

Dog::Dog(const Dog &dog) {
	*this = dog;
}

Dog &Dog::operator=(const Dog &dog) {
	setType(dog.getType());
	return *this;
}

Dog::~Dog() {

}

void	Dog::makeSound() const {
	std::cout << "Woof woof motherforker" << std::endl;
}
