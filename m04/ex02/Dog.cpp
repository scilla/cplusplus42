#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog constructor called" << std::endl;
	setType("Dog");
	brain = new Brain();
}

Dog::Dog(const Dog &dog) {
	std::cout << "Dog copy constructor called" << std::endl;
	brain = new Brain();
	*this = dog;
}

Dog &Dog::operator=(const Dog &dog) {
	std::cout << "Dog assignament operator called" << std::endl;
	setType(dog.getType());
	*brain = *dog.brain;
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete brain;
}

void	Dog::makeSound() const {
	std::cout << "Woof woof motherforker" << std::endl;
}

std::string		Dog::getIdea(unsigned int i) const
{
	return brain->getIdea(i);
}

void			Dog::setIdea(unsigned int i, const std::string & str)
{
	brain->setIdea(i, str);
}
