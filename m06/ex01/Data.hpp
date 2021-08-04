#ifndef DATA_HPP
#define DATA_HPP
#include <iostream>

struct Data
{
	int			i;
	bool		truth;
	std::string	text;
};

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

#endif /* DATA_HPP */
