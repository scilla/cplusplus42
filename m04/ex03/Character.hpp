#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <iostream>

class Character : public ICharacter
{
private:
	std::string _name;
	AMateria	*inventory[4];
public:
	Character(const std::string &name);
	Character(Character& character);
	Character& operator= (Character& character);
	~Character();
	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};

#endif /* CHARACTER_HPP */
