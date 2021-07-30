#include "Dog.hpp"

Dog::Dog() {
	type = "Dog";
}

Dog::Dog(const Dog &dog) {
	*this = dog;
}

Dog &Dog::operator=(const Dog &dog) {
	type = dog.type;
	return *this;
}

Dog::~Dog() {

}

void	Dog::makeSound() const {
	std::cout << "Woof woof motherforker" << std::endl;
}
