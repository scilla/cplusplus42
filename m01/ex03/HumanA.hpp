#ifndef HUMANA_CPP
# define HUMANA_CPP
# include "Weapon.hpp"

class HumanA
{
private:
	Weapon &weapon;
	std::string	name;
public:
	HumanA(std::string name, Weapon& weapon);
	~HumanA();
	void attack();
};

#endif