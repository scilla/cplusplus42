#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"
#include "textColors.hpp"

DiamondTrap::DiamondTrap(std::string name) :  ClapTrap(name), FragTrap(name), ScavTrap(name)
{
	_trapType = "DiamondTrap";
	_name = name;
	ClapTrap::_name = name + "_clap_name";
	set_hitPoints(FragTrap::get_hitPoints());
	set_energyPoints(ScavTrap::get_energyPoints());
	set_attackDamage(FragTrap::get_attackDamage());
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
	set_hitPoints(diamondtrap.get_hitPoints());
	set_attackDamage(diamondtrap.get_attackDamage());
	set_energyPoints(diamondtrap.get_energyPoints());
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

void DiamondTrap::whoAmI() {
	printName();
	std::cout << " or ";
	ClapTrap::printName();
	std::cout << " that is the question" << std::endl;
}

void	DiamondTrap::takeDamage(unsigned int amount)
{
	if (checkDeath())
		return ;
	if (amount > get_hitPoints())
		set_hitPoints(0);
	else
		set_hitPoints(get_hitPoints() - amount);
	printName();
	std::cout << " took " << amount << " points of damage! " << get_hitPoints() << " points remaining" << std::endl;
	if (!get_hitPoints()) {
		printName();
		std::cout << " died!" << std::endl;
	}
}

std::string	DiamondTrap::getName() const {
	return _name;
}

unsigned int 	DiamondTrap::get_hitPoints() const {
	return _hitPoints;
}
unsigned int 	DiamondTrap::get_energyPoints() const {
	return _energyPoints;
}
unsigned int 	DiamondTrap::get_attackDamage() const {
	return _attackDamage;
}

void	DiamondTrap::set_hitPoints(unsigned int n) {
	_hitPoints = n;
}
void	DiamondTrap::set_energyPoints(unsigned int n) {
	_energyPoints = n;
}
void	DiamondTrap::set_attackDamage(unsigned int n) {
	_attackDamage = n;
}
