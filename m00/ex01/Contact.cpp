#include "Contact.hpp"

Contact::Contact()
{
}

void Contact::setAttr(std::string str)
{
	static int i = 0;
	std::string	*arr[] = {
		&this->firstName,
		&this->lastName,
		&this->nickName,
		&this->phoneNumber,
		&this->darkestSecret
	};

	this->initialized = true;
	(*arr[i]).assign(str);
	i++;
	i = i % (sizeof(arr) / sizeof(arr[0]));
}

std::string Contact::getName() {
	return this->firstName;
}

bool	Contact::isInitialized() {
	return this->initialized;
}

std::string Contact::getInfo(int index) {
	std::string	arr[] = {
		this->firstName,
		this->lastName,
		this->nickName,
		this->phoneNumber,
		this->darkestSecret
	};
	return arr[index];
}

void	Contact::displayContact() {
	std::cout << "First Name: "<<this->firstName << std::endl;
	std::cout << "Last Name: "<<this->lastName << std::endl;
	std::cout << "Nickname: "<<this->nickName << std::endl;
	std::cout << "Phone Number: "<<this->phoneNumber << std::endl;
	std::cout << "Darkest Secret: "<<this->darkestSecret << std::endl;
}

Contact::~Contact()
{
}