#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>

class ClapTrap
{
private:
	std::string		_trapType;
protected:
	unsigned int 	_hitPoints;
	unsigned int 	_energyPoints;
	unsigned int 	_attackDamage;
	std::string		_name;
public:
	ClapTrap(std::string name);
	~ClapTrap();
	ClapTrap(const ClapTrap &claptrap);
	ClapTrap& operator= (const ClapTrap &claptrap);
	virtual void	printName() const;
	void	attack(std::string const & target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	bool	checkDeath() const;
	virtual int		getAttackDamage() const;
	std::string		getName() const;
	unsigned int 	_hitPoints() const;
	unsigned int 	_energyPoints() const;
	unsigned int 	_attackDamage() const;
};

#endif /* CLAPTRAP_HPP */
