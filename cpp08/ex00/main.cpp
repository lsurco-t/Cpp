#include "easyfind.hpp"
#include <iostream>
#include <list>
#include <vector>
#include <deque>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

int main(void){

	std::cout << GREEN "===== First test: Valid number to find in list =====" RESET << std::endl;
	std::list<int> firstList = {1, 2, 3, 4, 5};
	try{
		std::cout << "Elements of list: ";
		for (const int& n : firstList)
			std::cout << n << " ";
		std::cout << std::endl;
		std::list<int>::iterator it = ::easyfind(firstList, 3);
		std::cout << "The value found is: " << *it << std::endl; 
	}catch(const std::exception &e){
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << GREEN "\n===== Second test: Invalid number to find in list =====" RESET << std::endl;
	try{
		std::list<int>::iterator it = ::easyfind(firstList, 10);
		std::cout << "The value found is: " << *it << std::endl; 
	}catch(const std::exception &e){
		std::cout << RED "Error: " << e.what() << std::endl;
	}

	std::cout << GREEN "\n===== Third test: Valid number in vector =====" RESET << std::endl;
	std::vector<int> vectorOne = {10, 12, 20, 25};
	try{
		std::cout << "Elements of vector: ";
		for (unsigned int i = 0; i < std::size(vectorOne); i++)
			std::cout << vectorOne.at(i) << " ";
		std::cout << std::endl;
		std::vector<int>::iterator it = ::easyfind(vectorOne, 20);
		std::cout << "The value found is: " << *it << std::endl; 
	}catch(const std::exception &e){
		std::cout << RED "Error: " << e.what() << std::endl;
	}

	std::cout << GREEN "\n===== Fourth test: Valid number in deque =====" RESET << std::endl;
	std::deque<int> dequeOne = {1, 3, 5, 7, 9, 11, 13, 15};
	try{
		std::cout << "Elements of deque: ";
		for (unsigned int i = 0; i < std::size(dequeOne); i++)
			std::cout << dequeOne.at(i) << " ";
		std::cout << std::endl;
		std::deque<int>::iterator it = ::easyfind(dequeOne, 11);
		std::cout << "The value found is: " << *it << std::endl; 
	}catch(const std::exception &e){
		std::cout << RED "Error: " << e.what() << std::endl;
	}

	return 0;
}