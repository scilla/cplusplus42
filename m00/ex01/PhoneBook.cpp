#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->index = 0;
	this->initialized = false;
}

void PhoneBook::addContact()
{
	Contact 	contact;
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
	std::getline(std::cin, str);
	for (int i = 0; i < 5; i++)
	{
		std::cout << fields[i] << ": ";
		std::getline(std::cin, str);
		if (!str.length())
		{
			std::cout << "Field \"" << fields[i] << "\" can't be empty" << std::endl;
			i--;
			continue;
		}
		contact.setAttr(str);
	}
	this->contacts[this->index] = contact;
	this->index++;
	this->index = this->index % (sizeof(this->contacts) / sizeof(this->contacts[0]));
	std::cout << "Added " << contact.getName() << std::endl;
}

void PhoneBook::searchContact()
{
	std::string	info;
	Contact		contact;
	int			index;

	if (!this->initialized) {
		std::cout << "The phonebook is empty!" << std::endl;
		return ;
	}
	std::cout << "|index     |first name|last name |nickname  |" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	int maxind;
	for (int i = 0; i < 8; i++)
	{
		contact = this->contacts[i];
		if (!contact.isInitialized())
			break ;
		std::cout << "|";
		std::cout << std::setw(10);
		std::cout << i << "|";
		for (int p = 0; p < 3; p++) {
			info = contact.getInfo(p);
			if (info.length() > 10)
			{
				info.assign(info.substr(0, 9));
				info.append(".");
			}
			std::cout << std::setw(10);
			std::cout << info << "|";
		}
		std::cout << std::endl;
		maxind = i;
	}
	while (1)
	{
		std::cout << "Contact index [min 0, max " << maxind << "]: ";
		std::cin >> info;
		if (!isdigit(info[0]))
		{
			std::cout << "Invalid input" << std::endl;
			continue ;
		}
		index = stoi(info);
		if (index > maxind)
		{
			std::cout << "Too damn high" << std::endl;
			continue ;
		}
		break ;
	}
	this->contacts[index].displayContact();
}

PhoneBook::~PhoneBook()
{
}