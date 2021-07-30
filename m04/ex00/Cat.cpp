#include "Cat.hpp"

Cat::Cat() {
	type = "Cat";
}

Cat::Cat(const Cat &cat) {
	*this = cat;
}

Cat &Cat::operator=(const Cat &cat) {
	type = cat.type;
	return *this;
}

Cat::~Cat() {

}

void	Cat::makeSound() const {
	std::cout << "I'm gonna kill everyone here...cough cough I mean, meow meow" << std::endl;
}
