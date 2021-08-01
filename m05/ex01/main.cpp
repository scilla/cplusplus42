#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	Bureaucrat*	pippo = new Bureaucrat("Pippo Baudo", 20);
	Bureaucrat*	pupo = new Bureaucrat("Pupo Ghinazzi", 130);
	Form* form = new Form("Professional tricotomy", 80, 19);
	try
	{
		Form* badForm = new Form("This is bad", 1337, 12);
		std::cout << *badForm << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error creating form: " << e.what() << '\n';
	}

	std::cout << *form << std::endl;
	std::cout << *pippo << std::endl;
	std::cout << *pupo << std::endl;
	
	pupo->signForm(*form);
	pippo->signForm(*form);
	pippo->incrementGrade();
	pippo->signForm(*form);
	std::cout << *form;
	delete pippo;
	delete pupo;
	delete form;
	return 0;
}
