#include "RobotomyRequestForm.hpp"
#include <stdlib.h>
#include <time.h> 

RobotomyRequestForm::RobotomyRequestForm(std::string target): Form("robotomy", 45, 72)
{
	_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& form): Form(form)
{
	*this = form;
}

RobotomyRequestForm& RobotomyRequestForm::operator= (const RobotomyRequestForm& form)
{
	Form::operator=(form);
	_target = form.getTarget();
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

std::string RobotomyRequestForm::getTarget() const { return _target; }

void RobotomyRequestForm::_execute() const
{
	srand (time(NULL));
	int ran = rand();
	std::cout << "ziiingzaaaaanZAAAAAAAAANG" << std::endl;
	if (ran % 2)
		std::cout << _target << " has been successfully robotomized!" << std::endl;
	else
		std::cout << _target << " robotomy has been a successfull failure!" << std::endl;
}
