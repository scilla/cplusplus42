#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>

class ClapTrap
{
private:
	std::string		_name;
	unsigned int 	_hitPoints;
	unsigned int 	_energyPoints;
	unsigned int 	_attackDamage;
public:
	ClapTrap(std::string name);
	~ClapTrap();
	ClapTrap(const ClapTrap &claptrap);
	ClapTrap& operator= (const ClapTrap &claptrap);
	void	attack(std::string const & target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	bool	checkDeath() const;
	int		getAttackDamage() const;
	std::string		getName() const;
};

#endif /* CLAPTRAP_HPP */
