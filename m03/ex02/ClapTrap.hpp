#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>

class ClapTrap
{
private:
	std::string		_trapType;
	unsigned int 	_hitPoints;
	unsigned int 	_energyPoints;
	unsigned int 	_attackDamage;
protected:
	std::string		_name;
public:
	ClapTrap(std::string name);
	~ClapTrap();
	ClapTrap(const ClapTrap &claptrap);
	ClapTrap& operator= (const ClapTrap &claptrap);
	virtual void	printName() const;
	void	attack(std::string const & target);
	virtual void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	bool	checkDeath() const;
	std::string		getName() const;
	virtual unsigned int 	get_hitPoints() const;
	virtual unsigned int 	get_energyPoints() const;
	virtual unsigned int 	get_attackDamage() const;
	virtual void			set_hitPoints(unsigned int n);
	virtual void			set_energyPoints(unsigned int n);
	virtual void			set_attackDamage(unsigned int n);
};

#endif /* CLAPTRAP_HPP */
