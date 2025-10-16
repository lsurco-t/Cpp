#include "Intern.hpp"

Intern::Intern(){}

Intern::Intern(const Intern& other){
	(void)other;
}

Intern& Intern::operator=(const Intern& other){
	(void)other;
	return *this;
}

Intern::~Intern(){}

AForm* Intern::makeForm(const std::string& formName, const std::string& target){	
	std::string forms[] = {
		"ShrubberyCreationForm",
		"RobotomyRequestForm",
		"PresidentialPardonForm"
	};
	AForm* formsToCreate[] = {
		new ShrubberyCreationForm(target),
		new RobotomyRequestForm(target),
		new PresidentialPardonForm(target)
	};
	for (int i = 0; i < 3; i++){
		if (forms[i] == formName){
			std::cout << "Intern creates " << formName << std::endl;
			for (int j = 0; j < 3; j++){
				if (j != i)
					delete formsToCreate[j];
			}
			return formsToCreate[i];
		}
	}
	std::cout << "Intern failed to create " << formName << std::endl;
	for (int j = 0; j < 3; j++){
		delete formsToCreate[j];
	}
	return nullptr;
}