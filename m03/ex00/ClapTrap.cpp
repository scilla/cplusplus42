#include "ClapTrap.hpp"

bool	ClapTrap::checkDeath() const {
	if (!_hitPoints) {
		std::cout << _name << " is already dead" << std::endl;
		return 1;
	}
	return 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap HALLOOOOOOO I'm " << name << std::endl;
	_name = name;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &claptrap) {
	*this = claptrap;
}

ClapTrap& ClapTrap::operator= (const ClapTrap &claptrap) {
	_name = claptrap._name;
	_hitPoints = claptrap._hitPoints;
	_attackDamage = claptrap._attackDamage;
	_energyPoints = claptrap._energyPoints;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " just vanished into thin air" << std::endl;
}

void	ClapTrap::attack(std::string const & target)
{
	if (checkDeath())
		return ;
	if (_energyPoints)
	{
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
	}
	else
	{
		std::cout << "ClapTrap " << _name << " has no energy points left to attack " << target << std::endl;
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
	std::cout << "ClapTrap " << _name << " took " << amount << " points of damage! " << _hitPoints << " points remaining" << std::endl;
	if (!_hitPoints)
		std::cout << "ClapTrap " << _name << " died!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	_hitPoints += amount;
	std::cout << "ClapTrap " << _name << " has been repaired for " << amount << " hit points, "  << _hitPoints << " points remaining" << std::endl;
}

int		ClapTrap::getAttackDamage() const {
	return _attackDamage;
}

std::string		ClapTrap::getName() const {
	return _name;
}