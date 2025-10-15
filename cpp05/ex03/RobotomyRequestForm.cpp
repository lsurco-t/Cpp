#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm" ,72, 45) , _target(target){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), _target(other._target){}

RobotomyRequestForm::~RobotomyRequestForm(){}

void 	RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (!getIsSigned())
		throw FormIsNotSigned();
	if (executor.getGrade() > getExecuteGrade())
		throw AForm::GradeTooLowException();
	std::cout << "Drilling noises Rrrrrrrrrrrrrr" << std::endl;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::bernoulli_distribution robotomyChance(0.5);
	bool success = robotomyChance(gen);
	if (success)
		std::cout << "Robotomy on " << this->_target << " succeeded" << std::endl;
	else
		std::cout << "Robotomy on " << this->_target << " failed" << std::endl;
}