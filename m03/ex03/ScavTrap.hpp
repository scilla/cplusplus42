#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
private:
	std::string _trapType;
protected:
	bool isGuardGate;
	unsigned int 	_hitPoints;
	unsigned int 	_energyPoints;
	unsigned int 	_attackDamage;
public:
	ScavTrap(std::string name);
	~ScavTrap();
	ScavTrap(const ScavTrap &scavtrap);
	ScavTrap& operator= (const ScavTrap &scavtrap);
	void	attack(std::string const & target);
	virtual void	printName() const;
	void			guardGate();
};

#endif /* SCAVTRAP_HPP */
