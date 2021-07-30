#include "FragTrap.hpp"
#include "textColors.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	set_hitPoints(100);
	set_energyPoints(100);
	set_attackDamage(30);
	_trapType = "FragTrap";
	printName();
	std::cout << " thought itself into existence" << std::endl;
}

FragTrap::FragTrap(const FragTrap &fragtrap) : ClapTrap(fragtrap)
{
	*this = fragtrap;
}

FragTrap& FragTrap::operator= (const FragTrap &fragtrap) {
	_name = fragtrap._name;
	set_hitPoints(fragtrap.get_hitPoints());
	set_attackDamage(fragtrap.get_attackDamage());
	set_energyPoints(fragtrap.get_energyPoints());
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
	if (get_energyPoints())
	{
		printName();
		std::cout << " trow a rancid polpetta at " << target << ", the E. Coli caused " << get_attackDamage() << " points of damage!" << std::endl;
		set_energyPoints(get_energyPoints() - 1);
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

unsigned int 	FragTrap::get_hitPoints() const {
	return _hitPoints;
}
unsigned int 	FragTrap::get_energyPoints() const {
	return _energyPoints;
}
unsigned int 	FragTrap::get_attackDamage() const {
	return _attackDamage;
}

void	FragTrap::set_hitPoints(unsigned int n) {
	_hitPoints = n;
}
void	FragTrap::set_energyPoints(unsigned int n) {
	_energyPoints = n;
}
void	FragTrap::set_attackDamage(unsigned int n) {
	_attackDamage = n;
}