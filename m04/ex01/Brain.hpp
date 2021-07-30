#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <iostream>

class Brain
{
public:
	std::string	ideas[100];
	Brain();
	Brain(const Brain& brain);
	Brain& operator=(const Brain& brain);
	~Brain();
};

#endif /* BRAIN_HPP */
