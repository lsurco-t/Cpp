#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void){
	
	std::cout << "\033[32m======TEST 1: ShrubberyCreationForm - Valid execution======\033[0m" << std::endl;
	try {
		Bureaucrat b1("VIP", 1);
		Intern someRandomIntern;
		AForm* rrf;

		rrf = someRandomIntern.makeForm("ShrubberyCreationForm", "Bender");
		std::cout << "\033[33mForm created: \033[0m" << rrf->getName() << std::endl;
		b1.signForm(*rrf);
		b1.executeForm(*rrf);
		delete rrf;
	}
	catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\033[32m\n======TEST 2: RobotomyRequestForm - Valid execution======\033[0m" << std::endl;
	try {
		Bureaucrat b2("VP", 2);
		Intern someRandomInternAgain;
		AForm* rrfTwo;

		rrfTwo = someRandomInternAgain.makeForm("RobotomyRequestForm", "Bender");
		std::cout << "\033[33mForm created: \033[0m" << rrfTwo->getName() << std::endl;
		b2.signForm(*rrfTwo);
		b2.executeForm(*rrfTwo);
		delete rrfTwo;
	}
	catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\033[32m\n======TEST 3: Failed to create Form - Fired Intern======\033[0m" << std::endl;
	try {
		Bureaucrat b2("RRHH", 3);
		Intern firedIntern;
		AForm* rrfThree;

		rrfThree = firedIntern.makeForm("PresidentialPardonFormmm", "BenderThree");
		if (rrfThree)
			delete rrfThree;
	}
	catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	return 0;
}