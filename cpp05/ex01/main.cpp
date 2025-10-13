#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void){
	
	std::cout << "\033[32m======TEST 1: Valid grade======\033[0m" << std::endl;
	try {
		Bureaucrat b1("Pedro", 2);
		Form f1("Internship", 1, 4);

		std::cout << "\033[33mBefore promotion: \033[0m" <<  b1 << std::endl;
		b1.setGradeHigher();
		std::cout << "\033[33mAfter promotion: \033[0m" << b1 << std::endl;
		b1.signForm(f1);
		std::cout << "\033[33mForm signed: \033[0m" << std::boolalpha << f1.getIsSigned() << std::endl; 
		std::cout << "\033[33mFinal Bureaucrat: \033[0m" << b1 << std::endl;
		std::cout << "\033[33mFinal Form: \033[0m" << f1 << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\033[32m\n======TEST 2: Invalid grade======\033[0m" << std::endl;
	try {
		Bureaucrat b1("Alice", 2);
		Form f2("Traininship", 1, 4);

		std::cout << "\033[33mBefore promotion: \033[0m" <<  b1 << std::endl;
		std::cout << "\033[33mAfter promotion: \033[0m" << b1 << std::endl;
		b1.signForm(f2);
		std::cout << "\033[33mForm signed: \033[0m" << std::boolalpha << f2.getIsSigned() << std::endl; 
		std::cout << "\033[33mFinal Bureaucrat: \033[0m" << b1 << std::endl;
		std::cout << "\033[33mFinal Form: \033[0m" << f2 << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}