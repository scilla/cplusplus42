#ifndef INTERN_HPP
#define INTERN_HPP
#include <iostream>
#include <exception>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
public:
	Intern();
	Intern(const Intern& intern);
	Intern& operator= (const Intern& intern);
	~Intern();
	Form* makeForm(std::string formName, std::string formTarget);
	class FormNotFound : public std::exception
	{
		virtual const char* what() const throw();
	};
};

#endif /* INTERN_HPP */
