#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>

class Animal
{
private:
	std::string type;
public:
	Animal();
	Animal(const Animal &animal);
	Animal& operator=(const Animal &animal);
	virtual ~Animal();
	virtual void	makeSound() const;
	std::string		getType() const;
	void			setType(std::string type);
};

#endif /* ANIMAL_HPP */
