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
	virtual Animal& operator=(const Animal &animal);
	virtual ~Animal() = 0;
	virtual void	makeSound() const;
	virtual std::string		getType() const;
};

#endif /* ANIMAL_HPP */
