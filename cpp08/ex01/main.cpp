#include "Span.hpp"
#include <iostream>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

int main(void){

	std::cout << "====== Subject's test ======" << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	
	return 0;
}