#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"

class PhoneBook
{
private:
	Contact contacts[8];
	int		index;
	bool	initialized;
	void	displayContact();
public:
	PhoneBook();
	~PhoneBook();
	void	addContact();
	void	searchContact();
};


#endif