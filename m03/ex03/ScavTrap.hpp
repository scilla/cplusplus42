#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
private:
	std::string _trapType;
	unsigned int 	_hitPoints;
	unsigned int 	_energyPoints;
	unsigned int 	_attackDamage;
protected:
	bool isGuardGate;
public:
	ScavTrap(std::string name);
	~ScavTrap();
	ScavTrap(const ScavTrap &scavtrap);
	ScavTrap& operator= (const ScavTrap &scavtrap);
	void	attack(std::string const & target);
	virtual void	printName() const;
	void			guardGate();
	virtual unsigned int 	get_hitPoints() const;
	virtual unsigned int 	get_energyPoints() const;
	virtual unsigned int 	get_attackDamage() const;
	virtual void			set_hitPoints(unsigned int n);
	virtual void			set_energyPoints(unsigned int n);
	virtual void			set_attackDamage(unsigned int n);
};

#endif /* SCAVTRAP_HPP */
