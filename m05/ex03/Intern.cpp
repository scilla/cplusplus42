#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern& intern)
{
	*this = intern;
}

Intern& Intern::operator= (const Intern& intern)
{
	(void)intern;
	return *this;
}

Form* getShrubberyForm(std::string formTarget) {
	return new ShrubberyCreationForm(formTarget);
}

Form* getRobotomyForm(std::string formTarget) {
	return new RobotomyRequestForm(formTarget);
}

Form* getPardonForm(std::string formTarget) {
	return new PresidentialPardonForm(formTarget);
}

Intern::~Intern()
{
}

const char* Intern::FormNotFound::what() const throw() {
	return "Form not found";
}

Form* Intern::makeForm(std::string formName, std::string formTarget) {
	
	Form* (*formCatalogue[3])(std::string) = {
		getShrubberyForm,
		getRobotomyForm,
		getPardonForm
	};
	std::string titlesCatalogue[3] = {
		"shrubbery",
		"robotomy",
		"pardon"
	};
	for (unsigned int i=0; i < (sizeof(titlesCatalogue)/sizeof(titlesCatalogue[0])); i++) {
		if (!titlesCatalogue[i].compare(formName)) {
			std::cout << "Intern creates form " << formName << std::endl;
			return formCatalogue[i](formTarget);
		}
	}
	throw FormNotFound();
}
