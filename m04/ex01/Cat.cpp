#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat constructor called" << std::endl;
	setType("Cat");
	brain = new Brain();
}

Cat::Cat(const Cat &cat) {
	std::cout << "Cat copy constructor called" << std::endl;
	brain = new Brain();
	*this = cat;
}

Cat &Cat::operator=(const Cat &cat) {
	std::cout << "Cat assignament operator called" << std::endl;
	setType(cat.getType());
	*brain = *cat.brain;
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete brain;
}

void	Cat::makeSound() const {
	std::cout << "I'm gonna kill everyone here...cough cough I mean, meow meow" << std::endl;
}

std::string		Cat::getIdea(unsigned int i) const
{
	return brain->ideas[i];
}

void			Cat::setIdea(unsigned int i, const std::string & str)
{
	brain->ideas[i] = str;
}
