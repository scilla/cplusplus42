#include "oldlady.hpp"
#include "PhoneBook.hpp"
#include "Contact.hpp"

int main(void) {
	PhoneBook book;
	std::string str;

	while (1)
	{
		std::cout << "Cosa vuoi gioia: ";
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
	}
	return 0;
}