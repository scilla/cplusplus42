#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"
# include <iostream>

class PhoneBook
{
private:
	Contact contacts[8];
	void	getContact(int index);
	int		index;
public:
	PhoneBook();
	~PhoneBook();
	void	addContact();
	void	searchContact();
};


#endif