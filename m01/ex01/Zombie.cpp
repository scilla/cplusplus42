#include "Zombie.hpp"

Zombie::Zombie( std::string str )
{
	this->name = str;
}

Zombie::Zombie()
{
}

void	Zombie::setName(std::string name) {
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << "[DEBUG] " + this->name << "'s head exploded" << std::endl;
}

void Zombie::announce()
{
	std::cout << "<" + this->name + "> BraiiiiiiinnnzzzZ..." << std::endl;
}
