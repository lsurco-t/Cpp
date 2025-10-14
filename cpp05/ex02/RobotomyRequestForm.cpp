#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm" ,72, 45) , _target(target){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), _target(other._target){}

RobotomyRequestForm::~RobotomyRequestForm(){}

void 	RobotomyRequestForm::execute(Bureaucrat const & executor) const{

}