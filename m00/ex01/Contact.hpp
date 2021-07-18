#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <string>
# include <iostream>

class Contact
{
private:
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;
	std::string	firstName;
	bool		initialized;
public:
	Contact();
	~Contact();
	void 		setAttr(std::string str);
	std::string getName();
	std::string getInfo(int index);
	bool		isInitialized();
	void		displayContact();
};

#endif