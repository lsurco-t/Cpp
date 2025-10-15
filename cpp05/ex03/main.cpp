#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void){
	
	std::cout << "\033[32m======TEST 1: ShrubberyCreationForm - Valid execution======\033[0m" << std::endl;
	try {
		Bureaucrat b1("Pedro", 130);
		ShrubberyCreationForm form1("home");

		std::cout << "\033[33mBureaucrat: \033[0m" << b1 << std::endl;
		std::cout << "\033[33mForm: \033[0m" << form1 << std::endl;
		
		b1.signForm(form1);
		b1.executeForm(form1);
	}
	catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\033[32m\n======TEST 2: RobotomyRequestForm - Valid execution======\033[0m" << std::endl;
	try {
		Bureaucrat b2("Alice", 40);
		RobotomyRequestForm form2("Bender");

		std::cout << "\033[33mBureaucrat: \033[0m" << b2 << std::endl;
		std::cout << "\033[33mForm: \033[0m" << form2 << std::endl;
		
		b2.signForm(form2);
		b2.executeForm(form2);
	}
	catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\033[32m\n======TEST 3: PresidentialPardonForm - Valid execution======\033[0m" << std::endl;
	try {
		Bureaucrat b3("VIP", 1);
		PresidentialPardonForm form3("Arthur Dent");

		std::cout << "\033[33mBureaucrat: \033[0m" << b3 << std::endl;
		std::cout << "\033[33mForm: \033[0m" << form3 << std::endl;
		
		b3.signForm(form3);
		b3.executeForm(form3);
	}
	catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\033[32m\n======TEST 4: Execution without signing======\033[0m" << std::endl;
	try {
		Bureaucrat b4("John", 1);
		ShrubberyCreationForm form4("garden");

		std::cout << "\033[33mTrying to execute unsigned form...\033[0m" << std::endl;
		b4.executeForm(form4);
	}
	catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\033[32m\n======TEST 5: Insufficient grade for execution======\033[0m" << std::endl;
	try {
		Bureaucrat b5("Lowly", 150);
		ShrubberyCreationForm form5("tree");

		b5.signForm(form5);  // This should fail
		b5.executeForm(form5);
	}
	catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}