#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain* brain;
public:
	Cat();
	Cat(const Cat &cat);
	Cat &operator=(const Cat &cat);
	~Cat();
	virtual void	makeSound() const;
	std::string		getIdea(unsigned int i) const;
	void			setIdea(unsigned int i, const std::string & str);
};

#endif /* CAT_HPP */
