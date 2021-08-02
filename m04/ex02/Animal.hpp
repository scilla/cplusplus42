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
	void	setType(std::string str);
	virtual std::string		getIdea(unsigned int i) const = 0;
	virtual void			setIdea(unsigned int i, const std::string & str) = 0;
};

#endif /* ANIMAL_HPP */
