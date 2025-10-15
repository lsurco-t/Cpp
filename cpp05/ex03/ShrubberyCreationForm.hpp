#pragma once
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <fstream>
#include <iostream>

class ShrubberyCreationForm : public AForm{

	private:
		std::string _target;

	public:
		ShrubberyCreationForm() = delete;
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other) = delete;
		~ShrubberyCreationForm();

		void 	execute(Bureaucrat const & executor) const override;
};