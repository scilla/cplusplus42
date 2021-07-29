#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
private:
	std::string _trapType;
protected:
	bool isGuardGate;
public:
	ScavTrap(std::string name);
	~ScavTrap();
	ScavTrap(const ScavTrap &scavtrap);
	ScavTrap& operator= (const ScavTrap &scavtrap);
	virtual	void	attack(std::string const & target);
	virtual void	printName() const;
	void	guardGate();
};

#endif /* SCAVTRAP_HPP */
