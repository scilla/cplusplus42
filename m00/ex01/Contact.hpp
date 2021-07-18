#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <string>

class Contact
{
private:
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;
	std::string	firstName;
public:
	Contact();
	~Contact();
	int setAttr(std::string str);
	std::string getName();
};

#endif