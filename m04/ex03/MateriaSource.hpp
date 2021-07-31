#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria *recipes[4];
public:
	MateriaSource();
	MateriaSource(MateriaSource& source);
	MateriaSource& operator= (MateriaSource& source);
	~MateriaSource();
	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);
};

#endif /* MATERIASOURCE_HPP */
