#pragma once
#include "Form.hpp"
#include <iostream>

class Bureaucrat {

	private:
		const std::string _name;
		int				  _grade;

	public:
		Bureaucrat() = delete;
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other) = delete;
		~Bureaucrat();

		const std::string& getName(void) const;
		int 			   getGrade(void) const;

		void setGradeHigher();
		void setGradeLower();
		void signForm(Form &form);

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const noexcept override;
		};
		class GradeTooLowException  : public std::exception {
			public:
				const char* what() const noexcept override;
		};

};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);
