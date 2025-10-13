#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const Form& other)
	: _name(other._name), _isSigned(other._isSigned),
		_gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute){}

Form::~Form(){}

Form::Form(const std::string& name, const int gradeToSign, const int gradeToExecute)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign),
		_gradeToExecute(gradeToExecute){

	if(gradeToExecute > 150 || gradeToSign > 150)
		throw GradeTooLowException();
	else if (gradeToExecute < 1 || gradeToSign < 1)
		throw GradeTooHighException();	
	
	}

const 		std::string& Form::getName() const {
	return _name;
}

bool 		Form::getIsSigned() const {
	return _isSigned;
}

int 	Form::getSignGrade() const {
	return _gradeToSign;
}

int 	Form::getExecuteGrade() const {
	return _gradeToExecute;
}

void		Form::beSigned(const Bureaucrat& b){

	if (b.getGrade() > this->_gradeToSign)
		throw GradeTooLowException();
	this->_isSigned = true;
}

const char* Form::GradeTooHighException::what() const noexcept {
	return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const noexcept {
	return "Grade is too low!";
}

std::ostream& operator<<(std::ostream& out, const Form& f){
	out << "Form name: " << f.getName()
		<< ", Form signed: " << f.getIsSigned()
		<< ", Grade to sign: " << f.getSignGrade()
		<< ", Grade to execute: " << f.getExecuteGrade();
	return out;
}