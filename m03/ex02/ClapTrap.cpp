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
	set_hitPoints(10);
	set_energyPoints(10);
	set_attackDamage(0);
	_trapType = "ClapTrap";
	printName();
	std::cout << " showed up dressed like yesterday night" << std::endl;
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
	set_hitPoints(claptrap.get_hitPoints());
	set_attackDamage(claptrap.get_attackDamage());
	set_energyPoints(claptrap.get_energyPoints());
	_trapType = claptrap._trapType;
	return *this;
}

void	ClapTrap::attack(std::string const & target)
{
	if (checkDeath())
		return ;
	if (get_energyPoints())
	{
		printName();
		std::cout << " attacks " << target << ", causing " << get_attackDamage() << " points of damage!" << std::endl;
		set_energyPoints(get_energyPoints() - 1);
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

void	ClapTrap::beRepaired(unsigned int amount)
{
	set_hitPoints(get_hitPoints() + amount);
	printName();
	std::cout << " has been repaired for " << amount << " hit points, "  << get_hitPoints() << " points remaining" << std::endl;
}

std::string		ClapTrap::getName() const {
	return _name;
}

unsigned int 	ClapTrap::get_hitPoints() const {
	return _hitPoints;
}
unsigned int 	ClapTrap::get_energyPoints() const {
	return _energyPoints;
}
unsigned int 	ClapTrap::get_attackDamage() const {
	return _attackDamage;
}

void	ClapTrap::set_hitPoints(unsigned int n) {
	_hitPoints = n;
}
void	ClapTrap::set_energyPoints(unsigned int n) {
	_energyPoints = n;
}
void	ClapTrap::set_attackDamage(unsigned int n) {
	_attackDamage = n;
}
