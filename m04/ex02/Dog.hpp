#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain* brain;
public:
	Dog();
	Dog(const Dog &dog);
	Dog &operator=(const Dog &dog);
	~Dog();
	virtual void	makeSound() const;
	std::string		getIdea(unsigned int i) const;
	void			setIdea(unsigned int i, const std::string & str);
};

#endif /* DOG_HPP */
