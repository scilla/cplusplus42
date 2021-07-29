#include "ClapTrap.hpp"
#include "textColors.hpp"

bool	ClapTrap::checkDeath() const {
	if (!_hitPoints) {
		printName();
		std::cout << " is already dead" << std::endl;
		return 1;
	}
	return 0;
}

void	ClapTrap::printName() const {
	std::cout << GRN << _trapType << " " << _name << NC;
}

ClapTrap::ClapTrap(std::string name)
{
	_name = name;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
	_trapType = "ClapTrap";
	printName();
	std::cout << " showed up" << std::endl;
}

ClapTrap::~ClapTrap()
{
	printName();
	std::cout << " vanished into thin air" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &claptrap) {
	*this = claptrap;
}

ClapTrap& ClapTrap::operator= (const ClapTrap &claptrap) {
	_name = claptrap._name;
	_hitPoints = claptrap._hitPoints;
	_attackDamage = claptrap._attackDamage;
	_energyPoints = claptrap._energyPoints;
	_trapType = claptrap._trapType;
	return *this;
}

void	ClapTrap::attack(std::string const & target)
{
	if (checkDeath())
		return ;
	if (_energyPoints)
	{
		printName();
		std::cout << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
	}
	else
	{
		printName();
		std::cout << " has no energy point left to attack " << target << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (checkDeath())
		return ;
	if (amount > _hitPoints)
		_hitPoints = 0;
	else
		_hitPoints -= amount;
	printName();
	std::cout << " took " << amount << " points of damage! " << _hitPoints << " points remaining" << std::endl;
	if (!_hitPoints) {
		printName();
		std::cout << " died!" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	_hitPoints += amount;
	printName();
	std::cout << " has been repaired for " << amount << " hit points, "  << _hitPoints << " points remaining" << std::endl;
}

int		ClapTrap::getAttackDamage() const {
	return _attackDamage;
}

std::string		ClapTrap::getName() const {
	return _name;
}