#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const AForm& other)
	: _name(other._name), _isSigned(other._isSigned),
		_gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute){}

AForm::~AForm(){}

AForm::AForm(const std::string& name, const int gradeToSign, const int gradeToExecute)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign),
		_gradeToExecute(gradeToExecute){

	if(gradeToExecute > 150 || gradeToSign > 150)
		throw GradeTooLowException();
	else if (gradeToExecute < 1 || gradeToSign < 1)
		throw GradeTooHighException();	
	
	}

const 		std::string& AForm::getName() const {
	return _name;
}

bool 		AForm::getIsSigned() const {
	return _isSigned;
}

int 	AForm::getSignGrade() const {
	return _gradeToSign;
}

int 	AForm::getExecuteGrade() const {
	return _gradeToExecute;
}

void		AForm::beSigned(const Bureaucrat& b){

	if (b.getGrade() > this->_gradeToSign)
		throw GradeTooLowException();
	this->_isSigned = true;
}

const char* AForm::GradeTooHighException::what() const noexcept {
	return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const noexcept {
	return "Grade is too low!";
}

const char* AForm::FormIsNotSigned::what() const noexcept {
	return "Form is not signed";
}

std::ostream& operator<<(std::ostream& out, const AForm& f){
	out << "Form name: " << f.getName()
		<< ", Form signed: " << std::boolalpha << f.getIsSigned()
		<< ", Grade to sign: " << f.getSignGrade()
		<< ", Grade to execute: " << f.getExecuteGrade();
	return out;
}