#include "ScavTrap.hpp"
#include "textColors.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	_trapType = "ScavTrap";
	isGuardGate = false;
	printName();
	std::cout << " HALLOOOOOOO" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavtrap) : ClapTrap(scavtrap)
{
	*this = scavtrap;
}

ScavTrap& ScavTrap::operator= (const ScavTrap &scavtrap) {
	_name = scavtrap._name;
	_hitPoints = scavtrap._hitPoints;
	_attackDamage = scavtrap._attackDamage;
	_energyPoints = scavtrap._energyPoints;
	_trapType = scavtrap._trapType;
	return *this;
}

void	ScavTrap::printName() const {
	std::cout << RED << _trapType << " " << _name << NC;
}

ScavTrap::~ScavTrap()
{
	printName();
	std::cout << " vanished into thin air" << std::endl;
}

void ScavTrap::guardGate() {
	isGuardGate = true;
	printName();
	std::cout << " has enterred in Gate keeper mode!" << std::endl;
}