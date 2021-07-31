#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		recipes[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource& source)
{
	for (int i = 0; i < 4; i++)
		recipes[i] = NULL;
	*this = source;
}

MateriaSource& MateriaSource::operator= (MateriaSource& source)
{
	for (int i = 0; i < 4; i++) {
		if (recipes[i])
			delete recipes[i];
		recipes[i] = source.recipes[i]->clone();
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* amateria)
{
	for (int i = 0; i < 4; i++) {
		if (!recipes[i]) {
			recipes[i] = amateria->clone();
			std::cout << "Learned Materia " + amateria->getType() + " at index " << i << std::endl;
			return;
		}
	}
	std::cout << "No slot available to learned Materia " + amateria->getType() << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++) {
		if (recipes[i]->getType() == type) {
			return recipes[i]->clone();
		}
	}
	std::cout << " Materia " + type + " not found" << std::endl;
	return NULL;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		if (recipes[i])
			delete recipes[i];
}
