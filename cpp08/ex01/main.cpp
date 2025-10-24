#include "Span.hpp"
#include <iostream>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

int main(void){

    std::cout << GREEN "===== Test 1: Basic shortest & longest span =====" RESET << std::endl;
	try {
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch(std::exception &e) {
		std::cout << RED "Error: " << e.what() << RESET << std::endl;
	}

	try {
        std::cout << GREEN "\n===== Test 2: Not enough elements =====" RESET << std::endl;
        Span sp2(3);
        sp2.addNumber(10);
        std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << RED "Error: " << e.what() << RESET << std::endl;
    }

    try {
        std::cout << GREEN "\n===== Test 3: Using addManyNumbers() =====" RESET << std::endl;
        Span sp3(10);
        std::vector<int> values = {5, 1, 9, 3, 12, 20};
        sp3.addManyNumbers(values.begin(), values.end());
        std::cout << "Shortest span: " << sp3.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp3.longestSpan() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << RED "Error: " << e.what() << RESET << std::endl;
    }
	
	return 0;
}