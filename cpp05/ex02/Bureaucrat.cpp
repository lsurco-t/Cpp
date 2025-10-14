#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) 
	: _name(name), _grade(grade){
		if (_grade > 150)
			throw GradeTooLowException();
		else if (_grade < 1)
			throw GradeTooHighException();
	}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	: _name(other._name), _grade(other._grade) {}

Bureaucrat::~Bureaucrat(){}

const std::string& Bureaucrat::getName() const{
	return _name;
}

int Bureaucrat::getGrade() const{
	return _grade;
}

void Bureaucrat::setGradeHigher(){
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::setGradeLower(){
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const noexcept{
	return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept{
	return "Grade is too low!";
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b){
	out << b.getName() << ", bureaucrat grade " << b.getGrade();
	return out;
}

void Bureaucrat::signForm(AForm &form){
	try {
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception& e){
		std::cout << this->getName() << " could not sign " << form.getName()
		<< " because " << e.what() << std::endl;
	}
}

