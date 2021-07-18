#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->index = 0;
	this->initialized = false;
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

	this->initialized = true;
	contact = this->contacts[this->index];
	for (int i = 0; i < 5; i++)
	{
		std::cout << fields[i] << ": ";
		std::cin >> str;
		res = contact.setAttr(str);
	}
	this->contacts[this->index] = contact;
	this->index++;
	this->index = this->index % sizeof(this->contacts) / sizeof(this->contacts[0]);
	std::cout << "Added " << contact.getName() << std::endl;
}

void PhoneBook::searchContact()
{
	std::string	info;
	Contact		contact;

	if (!this->initialized) {
		std::cout << "The phonebook is empty!" << std::endl;
		return ;
	}
	std::cout << "|index     |first name|last name |nickname  |" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		contact = this->contacts[i];
		if (!contact.isInitialized())
			break ;
		std::cout << "|";
		for (int p = 0; p < 4; p++) {
			std::cout.width(11);
			std::cout << contact.getInfo(p) + "|";
		}
		std::cout << std::endl;
		std::cout.width(0);
	}
}

PhoneBook::~PhoneBook()
{
}