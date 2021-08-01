#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "Form.hpp"

class PresidentialPardonForm: public Form
{
private:
	std::string _target;
public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm& form);
	PresidentialPardonForm& operator= (const PresidentialPardonForm& form);
	~PresidentialPardonForm();
	void _execute() const;
	std::string getTarget() const;
};

#endif /* PRESIDENTIALPARDONFORM_HPP */
