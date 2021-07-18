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
		if (!str.compare("EXIT") || !str.compare("E"))
		{
			std::cout << "bye\n";
			break ;
		}
		else if (!str.compare("ADD") || !str.compare("A"))
		{
			book.addContact();
		} 
		else if (!str.compare("SEARCH") || !str.compare("S"))
		{
			book.searchContact();
		} 
	}
	return 0;
}