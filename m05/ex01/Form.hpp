#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	bool _signed;
	const unsigned int _gradeToExecute;
	const unsigned int _gradeToSign;
public:
	Form(std::string name, unsigned int gradeToExecute, unsigned int gradeToSign);
	Form(const Form& form);
	Form& operator= (const Form& form);
	~Form();
	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char* what() const throw();
	};
	void beSigned(Bureaucrat& b);
	unsigned int getGradeToExecute() const;
	unsigned int getGradeToSign() const;
	std::string getName() const;
	bool isSigned() const;
};

std::ostream& operator<< (std::ostream& o, Form& form);
#endif /* FORM_HPP */
