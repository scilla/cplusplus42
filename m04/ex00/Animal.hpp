#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>

class Animal
{
protected:
	std::string type;
private:
public:
	Animal();
	Animal(const Animal &animal);
	Animal &operator=(const Animal &animal);
	~Animal();
	virtual void	makeSound() const;
};

Animal::Animal()
{
	type = "Animal";
}

Animal::Animal(const Animal &animal) {
	*this = animal;
}

Animal &Animal::operator=(const Animal &animal) {
	
}

Animal::~Animal()
{
}

void Animal::makeSound() const {
	std::cout << "I'm a animal. I may or may not make sounds." << std::endl;
}

#endif /* ANIMAL_HPP */
