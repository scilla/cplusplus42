#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
private:
	std::string _trapType;
protected:
	bool isGuardGate;
public:
	FragTrap(std::string name);
	~FragTrap();
	FragTrap(const FragTrap &fragtrap);
	FragTrap& operator= (const FragTrap &fragtrap);
	virtual	void	attack(std::string const & target);
	virtual void	printName() const;
	void			highFivesGuys();
};

#endif /* FRAGTRAP_HPP */
