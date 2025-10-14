#pragma once
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

class RobotomyRequestForm : public AForm{

	private:
		std::string _target;

	public:
		RobotomyRequestForm() = delete;
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other) = delete;
		~RobotomyRequestForm();

		void 	execute(Bureaucrat const & executor) const override;
};