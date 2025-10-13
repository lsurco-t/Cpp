#pragma once
#include <iostream>

class Bureaucrat;

class Form {

	private:
		const std::string _name;
		bool  			  _isSigned;
		const int         _gradeToSign;
		const int		  _gradeToExecute;

	public:
		Form() = delete;
		Form(const Form& other);
		Form& operator=(const Form& other) = delete;
		~Form();
		Form(const std::string& name, const int gradeToSign, const int gradeToExecute);

		const 		std::string& getName(void) const;
		bool 		getIsSigned(void) const;
		int 		getSignGrade(void) const;
		int 		getExecuteGrade(void) const;
		void		beSigned(const Bureaucrat& b);

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const noexcept override;
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const noexcept override;
		};
};

std::ostream& operator<<(std::ostream& out, const Form& f);