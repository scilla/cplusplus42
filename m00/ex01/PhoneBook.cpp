#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->index = 0;
}

void PhoneBook::addContact()
{
	Contact 	contact;
	int			res;
	std::string	str;
	std::string	fields[] = {
		"First name",
		"Last name",
		"Nickname",
		"Phone number",
		"Darkest secret"
	};

	contact = this->contacts[this->index];
	for (int i = 0; i < 5; i++)
	{
		std::cout << fields[i] << ": ";
		std::cin >> str;
		res = contact.setAttr(str);
	}
	this->index++;
	this->index = this->index % sizeof(this->contacts) / sizeof(this->contacts[0]);
	std::cout << "Added " << contact.getName() << std::endl;
}

PhoneBook::~PhoneBook()
{
}