#include "Karen.hpp"

Karen::Karen(/* args */)
{
}

Karen::~Karen()
{
}

void	Karen::_displayTimestamp() {
	size_t		res;
	char		str[18];
	time_t		rawtime;
	struct tm	*timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	res = strftime(str, 19, "[%Y%m%d_%H%M%S: ", timeinfo);
	std::cout << str;
}

void Karen::debug( void ) {
	this->_displayTimestamp();
	std::cout << "DEBUG] " << std::endl;
}

void Karen::info( void ) {
	this->_displayTimestamp();
	std::cout << "INFO] " << std::endl;
}

void Karen::warning( void ) {
	this->_displayTimestamp();
	std::cout << "WARNING] " << std::endl;
}

void Karen::error( void ) {
	this->_displayTimestamp();
	std::cout << "ERROR] " << std::endl;
}
