#include "Form.hpp"

Form::Form(std::string name, unsigned int gradeToExecute, unsigned int gradeToSign) :
	_name(name), _gradeToExecute(gradeToExecute), _gradeToSign(gradeToSign)
{
	if (gradeToExecute < 1 || gradeToSign < 1)
		throw GradeTooHighException();
	if (gradeToExecute > 150 || gradeToSign > 150)
		throw GradeTooLowException();
	_signed = false;
}

Form::Form(const Form& form)
: _name(form.getName()), _gradeToExecute(form.getGradeToExecute()), _gradeToSign(form.getGradeToSign())
{
	*this = form;
}

Form& Form::operator= (const Form& form)
{
	_signed = form.isSigned();
	return *this;
}

Form::~Form() {}

const char* Form::GradeTooHighException::what() const throw() {
	return "Grade is too damn high";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

const char* Form::FormNotSignedException::what() const throw() {
	return "Form has not been signed";
}

unsigned int Form::getGradeToExecute() const { return _gradeToExecute;}
unsigned int Form::getGradeToSign() const { return _gradeToSign;}
std::string Form::getName() const { return _name;}
bool Form::isSigned() const { return _signed;}

std::ostream& operator<< (std::ostream& o, Form& form)
{
	o << YLW;
	o << "----------------Form Report----------------" << std::endl;
	o << "  Form Name: \t\t" << form.getName() << std::endl;
	o << "  Grade To Execute: \t" << form.getGradeToExecute() << std::endl;
	o << "  Grade To Sign: \t" << form.getGradeToSign() << std::endl;
	o << "  Is Signed: \t\t" << (form.isSigned() ? "Yes": "No") << std::endl;
	o << "----------------End Report-----------------" << std::endl;
	o << NC;
	return o;
}

void Form::beSigned(Bureaucrat& b)
{
	if (b.getGrade() > getGradeToSign())
		throw GradeTooLowException();
	_signed = true;
}

void Form::execute(const Bureaucrat& executor) const
{
	if (!isSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();
	_execute();
}
