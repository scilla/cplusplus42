#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	WrongCat();
	WrongCat(const WrongCat &cat);
	WrongCat &operator=(const WrongCat &cat);
	~WrongCat();
	void	makeSound() const;
};

#endif /* WRONGCAT_HPP */
