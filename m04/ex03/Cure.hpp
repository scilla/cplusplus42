#ifndef CURE_HPP
#define CURE_HPP
#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure();
	Cure(const Cure& cure);
	Cure& operator= (const Cure& cure);
	Cure* clone() const;
	~Cure();
	void use(ICharacter& target);
};

#endif /* CURE_HPP */
