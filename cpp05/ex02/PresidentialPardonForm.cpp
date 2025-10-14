#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("PresidentialPardonForm", 25 , 5), _target(target){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) 
	: AForm(other), _target(other._target){}

PresidentialPardonForm::~PresidentialPardonForm(){}

void 	PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (executor.getGrade() > getSignGrade())
		throw GradeTooLowException();
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;	
}