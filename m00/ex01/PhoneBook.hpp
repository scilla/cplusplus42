#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"
# include <iostream>

class PhoneBook
{
private:
	Contact contacts[8];
	int		index;
	bool	initialized;
public:
	PhoneBook();
	~PhoneBook();
	void	addContact();
	void	searchContact();
};


#endif