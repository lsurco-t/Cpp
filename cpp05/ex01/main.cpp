#include "Bureaucrat.hpp"

int main(void){
	
	std::cout << "\033[32m======TEST 1: Valid increment of grade======\033[0m" << std::endl;
	try {
		Bureaucrat b1("Pedro", 2);
		std::cout << b1 << std::endl;
		b1.setGradeHigher();
		std::cout << b1 << std::endl; 
	}
	catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\033[32m\n======TEST 2: Too low grade at construction======\033[0m" << std::endl;
	try {
		Bureaucrat b2("Alice", 151);
		std::cout << b2 << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\033[32m\n=====TEST 3: Too high grade at construction=====\033[0m" << std::endl;
	try {
		Bureaucrat b3("Pep", 0);
		std::cout << b3 << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\033[32m\n=====TEST 4: Grade went too high=====\033[0m" << std::endl;
	try {
		Bureaucrat b4("Marta", 1);
		std::cout << b4 << std::endl;
		b4.setGradeHigher();
		std::cout << b4 << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\033[32m\n=====TEST 5: Grade went too low=====\033[0m" << std::endl;
	try {
		Bureaucrat b5("Ana", 150);
		std::cout << b5 << std::endl;
		b5.setGradeLower();
		std::cout << b5 << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	return 0;
}