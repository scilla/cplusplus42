#include "Contact.hpp"

Contact::Contact()
{
}

int Contact::setAttr(std::string str)
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
	if (!i)
		return (1);
	return (0);
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

Contact::~Contact()
{
}