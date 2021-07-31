#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
}

Cure::Cure(const Cure& cure) : AMateria(cure.getType())
{
}

Cure& Cure::operator= (const Cure& cure)
{
	this->type = cure.getType();
	return *this;
}

Cure* Cure::clone() const
{
	Cure *cure = new Cure(*this);
	return cure;
}

Cure::~Cure()
{
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " + target.getName() + "’s wounds *" << std::endl;
}
