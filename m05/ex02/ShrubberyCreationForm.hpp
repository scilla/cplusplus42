#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "Form.hpp"

class ShrubberyCreationForm: public Form
{
private:
	std::string _target;
public:
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm& form);
	ShrubberyCreationForm& operator= (const ShrubberyCreationForm& form);
	~ShrubberyCreationForm();
	void _execute() const;
	std::string getTarget() const;
};

#endif /* SHRUBBERYCREATIONFORM_HPP */
