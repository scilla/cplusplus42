#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "Form.hpp"

class RobotomyRequestForm: public Form
{
private:
	std::string _target;
public:
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm& form);
	RobotomyRequestForm& operator= (const RobotomyRequestForm& form);
	~RobotomyRequestForm();
	void _execute() const;
	std::string getTarget() const;
};

#endif /* ROBOTOMYREQUESTFORM_HPP */
