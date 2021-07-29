#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
private:
	std::string _trapType;
protected:
	unsigned int 	_hitPoints;
	unsigned int 	_energyPoints;
	unsigned int 	_attackDamage;
public:
	FragTrap(std::string name);
	~FragTrap();
	FragTrap(const FragTrap &fragtrap);
	FragTrap& operator= (const FragTrap &fragtrap);
	void	attack(std::string const & target);
	virtual void	printName() const;
	void			highFivesGuys();
};

#endif /* FRAGTRAP_HPP */
