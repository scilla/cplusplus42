#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, unsigned int n) : _name(name)
{
	if (n < 1)
		throw GradeTooHighException();
	if (n > 150)
		throw GradeTooLowException();
	_grade = n;
}

Bureaucrat::Bureaucrat(const Bureaucrat& b) : _name(b.getName())
{
	*this = b;
}

Bureaucrat& Bureaucrat::operator= (const Bureaucrat& b)
{
	_grade = b.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat()
{
}

unsigned int Bureaucrat::getGrade() const { return _grade; }
std::string Bureaucrat::getName() const { return _name; }

void Bureaucrat::incrementGrade()
{
	if (_grade == 1)
		throw GradeTooHighException();
	_grade--;
	std::cout << "Grade of bureaucrat " + getName() + " incremented to " << getGrade() << std::endl;
}

void Bureaucrat::decrementGrade()
{
	if (_grade == 150)
		throw GradeTooLowException();
	_grade++;
	std::cout << "Grade of bureaucrat " + getName() + " decremented to " << getGrade() << std::endl;
}

std::ostream& operator<< (std::ostream& o, const Bureaucrat& b) {
	o << b.getName() + ", bureaucrat grade " << b.getGrade();
	return o;
}

void Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << GRN << getName() + " signs " + form.getName() << NC << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << getName() + " cannot sign " + form.getName() + " because " + e.what() << NC << std::endl;
	}
}

void Bureaucrat::executeForm(const Form& form) {
	try
	{
		form.execute(*this);
		std::cout << CYN << getName() << " executed " << form.getName() << NC << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << NC << '\n';
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too damn high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}
