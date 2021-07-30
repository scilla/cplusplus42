#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap
{
private:
	std::string _trapType;
	std::string	_name;
	unsigned int 	_hitPoints;
	unsigned int 	_energyPoints;
	unsigned int 	_attackDamage;
protected:
public:
	DiamondTrap(std::string name);
	~DiamondTrap();
	DiamondTrap(const DiamondTrap &diamondtrap);
	DiamondTrap& operator= (const DiamondTrap &diamondtrap);
	void 		printName() const;
	std::string	getName() const;
	void 		whoAmI();
	using 		ScavTrap::attack;
	void	takeDamage(unsigned int amount);
	virtual unsigned int 	get_hitPoints() const;
	virtual unsigned int 	get_energyPoints() const;
	virtual unsigned int 	get_attackDamage() const;
	virtual void			set_hitPoints(unsigned int n);
	virtual void			set_energyPoints(unsigned int n);
	virtual void			set_attackDamage(unsigned int n);
};

#endif /* DIAMONDTRAP_HPP */
