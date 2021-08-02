#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	
	std::cout << 4.2;
	Bureaucrat* pupo = new Bureaucrat("Gigi Di Maio", 73);
	Bureaucrat* pippo = new Bureaucrat("Mario Draghi", 46);
	Bureaucrat* president = new Bureaucrat("Sergio Mattarella", 1);
	Intern* roberto = new Intern();
	try
	{
		Form* ohNooo = roberto->makeForm("andiamo a fumare?", "Stefano");
		(void)ohNooo;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	Form* shrubbery = roberto->makeForm("shrubbery", "The Hub");
	Form* robotomy = roberto->makeForm("robotomy", "Bimby X-100");
	Form* pardon = roberto->makeForm("pardon", "Dr. Gerry Scotty");

	std::cout << std::endl << *shrubbery;
	pupo->executeForm(*shrubbery);
	pupo->signForm(*shrubbery);
	pupo->executeForm(*shrubbery);

	std::cout << std::endl << *robotomy;
	pupo->executeForm(*robotomy);
	pupo->signForm(*robotomy);
	pupo->incrementGrade();
	pupo->signForm(*robotomy);
	pippo->executeForm(*robotomy);
	pippo->incrementGrade();
	pippo->executeForm(*robotomy);
	
	std::cout << std::endl << *pardon;
	pupo->executeForm(*pardon);
	pupo->signForm(*pardon);
	pippo->signForm(*pardon);
	president->signForm(*pardon);
	president->executeForm(*pardon);

	return 0;
}
