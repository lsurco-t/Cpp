#pragma once
#include <iostream>

class Bureaucrat;

class AForm {

	private:
		const std::string _name;
		bool  			  _isSigned;
		const int         _gradeToSign;
		const int		  _gradeToExecute;

	public:
		AForm() = delete;
		AForm(const AForm& other);
		AForm& operator=(const AForm& other) = delete;
		virtual ~AForm();
		AForm(const std::string& name, const int gradeToSign, const int gradeToExecute);

		const 		std::string& getName(void) const;
		bool 		getIsSigned(void) const;
		int 		getSignGrade(void) const;
		int 		getExecuteGrade(void) const;
		void		beSigned(const Bureaucrat& b);
		virtual void 	execute(Bureaucrat const & executor) const = 0;

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const noexcept override;
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const noexcept override;
		};
		class FormIsNotSigned : public std::exception {
			public:
				const char* what() const noexcept override;
		};
};

std::ostream& operator<<(std::ostream& out, const AForm& f);