#include "Cat.hpp"

Cat::Cat() {
	setType("Cat");
}

Cat::Cat(const Cat &cat) {
	*this = cat;
}

Cat &Cat::operator=(const Cat &cat) {
	setType(cat.getType());
	return *this;
}

Cat::~Cat() {

}

void	Cat::makeSound() const {
	std::cout << "I'm gonna kill everyone here...cough cough I mean, meow meow" << std::endl;
}
