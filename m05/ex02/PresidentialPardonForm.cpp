#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target): Form("pardon", 5, 25)
{
	_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& form): Form(form)
{
	*this = form;
}

PresidentialPardonForm& PresidentialPardonForm::operator= (const PresidentialPardonForm& form)
{
	Form::operator=(form);
	_target = form.getTarget();
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

std::string PresidentialPardonForm::getTarget() const { return _target; }

void PresidentialPardonForm::_execute() const
{
	std::cout << _target << " has been pardoned by Sergio Mattarella" << std::endl;
}
