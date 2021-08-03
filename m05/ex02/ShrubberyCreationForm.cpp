#include "ShrubberyCreationForm.hpp"
#include <fstream>
#if __APPLE__
# define APPEND std::iostream::app
#else
# define APPEND std::_S_app
#endif


ShrubberyCreationForm::ShrubberyCreationForm(std::string target): Form("shrubbery", 137, 145)
{
	_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& form): Form(form)
{
	*this = form;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator= (const ShrubberyCreationForm& form)
{
	Form::operator=(form);
	_target = form.getTarget();
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

std::string ShrubberyCreationForm::getTarget() const { return _target; }

void ShrubberyCreationForm::_execute() const
{
	std::ofstream	outFile;
	std::string		fileName;

	fileName.assign(_target);
	fileName.append("_shrubbery");
	outFile.open(fileName.c_str(), std::iostream::app);
	outFile << "\n\
               ,@@@@@@@,\n\
       ,,,.   ,@@@@@@/@@,  .oo8888o.\n\
    ,&\%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n\
   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n\
   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n\
   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n\
   `&%\\ ` /%&'    |.|        \\ '|8'\n\
       |o|        | |         | |\n\
       |.|        | |         | |\n\
    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_\n\
	\n";
	outFile.close();
}
