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
	std::cout << " GTFO'd" << std::endl;
}

void	ScavTrap::attack(std::string const & target)
{
	if (checkDeath())
		return ;
	if (_energyPoints)
	{
		printName();
		std::cout << " farted towards " << target << ", the smell caused " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
	}
	else
	{
		printName();
		std::cout << " has no energy point left to attack " << target << std::endl;
	}
}

void ScavTrap::guardGate() {
	printName();
	if (!isGuardGate)
		std::cout << " has enterred Gate keeper mode!" << std::endl;
	else
		std::cout << " has exited Gate keeper mode!" << std::endl;
	isGuardGate = !isGuardGate;
}