#pragma once
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

class PresidentialPardonForm : public AForm {

	private:
		std::string _target;

	public:
		PresidentialPardonForm() = delete;
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other) = delete;
		~PresidentialPardonForm();

		void 	execute(Bureaucrat const & executor) const override;

};