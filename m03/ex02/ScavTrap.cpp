#include "ScavTrap.hpp"
#include "textColors.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	set_hitPoints(100);
	set_energyPoints(50);
	set_attackDamage(20);
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
	set_hitPoints(scavtrap.get_hitPoints());
	set_attackDamage(scavtrap.get_attackDamage());
	set_energyPoints(scavtrap.get_energyPoints());
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
	if (get_energyPoints())
	{
		printName();
		
		std::cout << " farted towards " << target << ", the smell caused " << get_attackDamage() << " points of damage!" << std::endl;
		set_energyPoints(get_energyPoints() - 1);
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

unsigned int 	ScavTrap::get_hitPoints() const {
	return _hitPoints;
}
unsigned int 	ScavTrap::get_energyPoints() const {
	return _energyPoints;
}
unsigned int 	ScavTrap::get_attackDamage() const {
	return _attackDamage;
}
void	ScavTrap::set_hitPoints(unsigned int n) {
	_hitPoints = n;
}
void	ScavTrap::set_energyPoints(unsigned int n) {
	_energyPoints = n;
}
void	ScavTrap::set_attackDamage(unsigned int n) {
	_attackDamage = n;
}