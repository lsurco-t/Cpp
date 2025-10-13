#pragma once
#include "AForm.hpp"
#include <iostream>

class ShrubberyCreationForm {

	private:
		const int _gradetoSign;
		const int _gradetoExecute;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(Form& form);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();
};