#include "oldlady.hpp"
#include "PhoneBook.hpp"
#include "Contact.hpp"

int main(void) {
	PhoneBook book;
	std::string str;

	while (1)
	{
		std::cout << "Command: ";
		std::cin >> str;
		if (!str.compare("EXIT"))
		{
			std::cout << "bye\n";
			break ;
		}
		else if (!str.compare("ADD"))
		{
			book.addContact();
		} 
		else if (!str.compare("SEARCH"))
		{
			book.searchContact();
		} 
	}
	return 0;
}