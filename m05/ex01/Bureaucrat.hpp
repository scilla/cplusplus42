#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
	const std::string	_name;
	unsigned int		_grade;
public:
	Bureaucrat(std::string name, unsigned int n);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat& b);
	Bureaucrat& operator= (const Bureaucrat& b);
	unsigned int getGrade() const;
	std::string getName() const;
	void incrementGrade();
	void decrementGrade();
	void signForm(Form& form);
	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char* what() const throw();
	};
};

std::ostream& operator<< (std::ostream& o, const Bureaucrat& b);


#endif /* BUREAUCRAT_HPP */
