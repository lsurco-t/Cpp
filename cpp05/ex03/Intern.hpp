#pragma once
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

class Intern {

	public:
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern();

		void makeForm(const AForm& form, const std::string& target);
};