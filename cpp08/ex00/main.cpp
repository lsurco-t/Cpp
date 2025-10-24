#include "easyfind.hpp"
#include <iostream>
#include <list>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

int main(void){

	std::cout << GREEN "===== First test: Valid number to find (3) =====" RESET << std::endl;
	std::list<int> firstList = {1, 2, 3, 4, 5};
	try{
		auto it = ::easyfind(firstList, 3);
		std::cout << "The value searched is: " << *it << std::endl; 
	}catch(std::exception &e){
		std::cout << "Error: " << std::endl;
	}

	std::cout << GREEN "===== Second test: Invalid number to find (10) =====" RESET << std::endl;
	try{
		auto it = ::easyfind(firstList, 10);
		std::cout << "The value search is: " << *it << std::endl; 
	}catch(std::exception &e){
		std::cout << RED "Error: " << e.what() << std::endl;
	}

	return 0;
}