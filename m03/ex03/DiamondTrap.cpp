#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"
#include "textColors.hpp"

DiamondTrap::DiamondTrap(std::string name) :  ClapTrap(name), FragTrap(name), ScavTrap(name)
{
	_trapType = "DiamondTrap";
	_name = name;
	ClapTrap::_name = name + "_clap_name";
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	printName();
	std::cout << " I'm so hard" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondtrap) : ClapTrap(diamondtrap), FragTrap(diamondtrap), ScavTrap(diamondtrap) 
{
	*this = diamondtrap;
}

DiamondTrap& DiamondTrap::operator= (const DiamondTrap &diamondtrap) {
	_name = diamondtrap._name;
	ClapTrap::_name = diamondtrap.ClapTrap::_name;
	_hitPoints = diamondtrap._hitPoints;
	_attackDamage = diamondtrap._attackDamage;
	_energyPoints = diamondtrap._energyPoints;
	_trapType = diamondtrap._trapType;
	return *this;
}

void	DiamondTrap::printName() const {
	std::cout << CYN << _trapType << " " << _name << NC;
}

DiamondTrap::~DiamondTrap()
{
	printName();
	std::cout << " fell into a pit of radioactive lava" << std::endl;
}

int		DiamondTrap::getAttackDamage() const {
	return _attackDamage;
}

void DiamondTrap::whoAmI() {
	printName();
	std::cout << " or ";
	ClapTrap::printName();
	std::cout << " that is the question" << std::endl;
}

std::string	DiamondTrap::getName() const {
		return _name;
}