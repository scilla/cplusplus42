#include "Character.hpp"

Character::Character(const std::string &name)
{
	_name = name;
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}


Character::Character(Character& character)
{
	*this = character;
	this->_name = character.getName();
}

Character& Character::operator= (Character& character)
{
	// not copying _name on purpose
	for (int i = 0; i < 4; i++) {
		if (character.inventory[i]) {
			inventory[i] = character.inventory[i]->clone();
			delete character.inventory[i];
			character.inventory[i] = NULL;
		}
	}
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++) {
		delete inventory[i];
	}
}

std::string const & Character::getName() const { return _name; }

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++) {
		if (!inventory[i]) {
			inventory[i] = m;
			std::cout << "Materia " + m->getType() + " equipped at index " << i << std::endl;
			return;
		}
	}
	std::cout << "Unable to equip Materia " + m->getType() + ", inventory is full" << std::endl;
}

void Character::unequip(int idx) {
	if (idx > 3 or idx < 0) {
		std::cout << "Index OOB" << std::endl;
	}
	if (!inventory[idx]) {
		std::cout << "Inventory is already empty at index " << idx << std::endl;
		return;
	}
	std::cout << "Materia " + inventory[idx]->getType() + " unequipped from index " << idx << std::endl;
	inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (inventory[idx]) {
		inventory[idx]->use(target);
		delete inventory[idx];
		inventory[idx] = NULL;
	} else {
		std::cout << "Inventory is empty at index " << idx << std::endl;
	}
}

