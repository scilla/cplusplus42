#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	try
	{
		Bureaucrat troppoAlto("Giovanni", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat troppoBasso("Brunetta", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	Bureaucrat alto("Giovanni", 2);
	Bureaucrat basso("Giacomo", 149);

	try
	{
		alto.incrementGrade();
		alto.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		basso.decrementGrade();
		basso.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "Output test >> " << alto << " <<" <<std::endl;

	return 0;
}
