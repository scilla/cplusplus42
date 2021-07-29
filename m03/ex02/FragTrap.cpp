#include "FragTrap.hpp"
#include "textColors.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	_trapType = "ScavTrap";
	isGuardGate = false;
	printName();
	std::cout << " HALLOOOOOOO" << std::endl;
}

FragTrap::FragTrap(const FragTrap &fragtrap) : ClapTrap(fragtrap)
{
	*this = fragtrap;
}

FragTrap& FragTrap::operator= (const FragTrap &fragtrap) {
	_name = fragtrap._name;
	_hitPoints = fragtrap._hitPoints;
	_attackDamage = fragtrap._attackDamage;
	_energyPoints = fragtrap._energyPoints;
	_trapType = fragtrap._trapType;
	return *this;
}

void	FragTrap::printName() const {
	std::cout << YLW << _trapType << " " << _name << NC;
}

FragTrap::~FragTrap()
{
	printName();
	std::cout << " was very confused and drove off a cliff" << std::endl;
}

void	FragTrap::attack(std::string const & target)
{
	if (checkDeath())
		return ;
	if (_energyPoints)
	{
		printName();
		std::cout << " trow a rancid polpetta at " << target << ", the E. Coli caused " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
	}
	else
	{
		printName();
		std::cout << " has no energy point left to attack " << target << std::endl;
	}
}

void FragTrap::highFivesGuys() {
	std::string str;

	while (1)
	{
		printName();
		std::cout << " says: \"Give me a 5!!\">";
		std::cin >> str;
		if (!str.compare("5") || !str.compare("cinque"))
			break ;
	}
	printName();
	std::cout << " retracts its hand very quickly, \
leaving you standing there like a fool and you \
start thinking about all the mistakes you made in your \
life." << std::endl;
}