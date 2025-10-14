#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), _target(other._target){}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

void 	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (!getIsSigned())
		throw FormIsNotSigned();
	if (executor.getGrade() > getExecuteGrade())
		throw GradeTooLowException();
	std::ofstream outfile(_target + "_shrubbery");
	if (!outfile.is_open())
		throw std::ios_base::failure("failed to open file");
	outfile << "🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳";
	outfile.close();
}