#include "Contact.hpp"

Contact::Contact(std::string firstName,
	std::string lastName,
	std::string nickName,
	std::string phoneNumber,
	std::string	darkestSecret)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->nickName = nickName;
	this->phoneNumber = phoneNumber;
	this->darkestSecret = darkestSecret;
}

Contact::~Contact()
{
}