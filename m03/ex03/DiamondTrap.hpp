#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap
{
private:
	std::string _trapType;
	std::string	_name;
protected:
	unsigned int 	_hitPoints;
	unsigned int 	_energyPoints;
	unsigned int 	_attackDamage;
public:
	DiamondTrap(std::string name);
	~DiamondTrap();
	DiamondTrap(const DiamondTrap &diamondtrap);
	DiamondTrap& operator= (const DiamondTrap &diamondtrap);
	void 		printName() const;
	std::string	getName() const;
	void 		whoAmI();
	int			getAttackDamage() const;
	using 		ScavTrap::attack;
};

#endif /* DIAMONDTRAP_HPP */
