#pragma once
#include <iostream>

class Bureaucrat {

	private:
		std::string _name;
		unsigned int _grade;

	public:
		Bureaucrat(std::string name, unsigned int grade);
		~Bureaucrat();

		void setName(const std::string& name);
		void setGrade(unsigned int grade);
		const std::string& getName(void) const;
		const std::string& getGrade(void) const;

};