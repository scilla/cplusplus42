#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
private:
	std::string _trapType;
	unsigned int 	_hitPoints;
	unsigned int 	_energyPoints;
	unsigned int 	_attackDamage;
protected:
public:
	FragTrap(std::string name);
	~FragTrap();
	FragTrap(const FragTrap &fragtrap);
	FragTrap& operator= (const FragTrap &fragtrap);
	void	attack(std::string const & target);
	virtual void	printName() const;
	void			highFivesGuys();
	virtual unsigned int 	get_hitPoints() const;
	virtual unsigned int 	get_energyPoints() const;
	virtual unsigned int 	get_attackDamage() const;
	virtual void			set_hitPoints(unsigned int n);
	virtual void			set_energyPoints(unsigned int n);
	virtual void			set_attackDamage(unsigned int n);
};

#endif /* FRAGTRAP_HPP */
