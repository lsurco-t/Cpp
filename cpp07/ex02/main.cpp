#include "Array.hpp"
#include <iostream>

#define GREEN "\033[32m"
#define RESET "\033[0m"

int main(void){

	std::cout << GREEN "===== Test 1: Empty array =====" RESET << std::endl;
	Array<int> empty;
	std::cout << "Empty array size: " << empty.size() << std::endl;

	std::cout << GREEN "===== Test 2: Array with size defined =====" RESET << std::endl;
	Array<int> numbers(5);
	std::cout << "Number size: " << numbers.size() << std::endl;

	std::cout << GREEN "===== Test 3: Modify elements in array =====" RESET << std::endl;
	for (unsigned int i = 0; i < numbers.size(); i++){
		numbers[i] = i * 10;
		std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
	}

	std::cout << GREEN "===== Test 4: Copy constructor =====" RESET << std::endl;
	Array<int> copy(numbers);
	copy[0] = 99;
	std::cout << "Original: " << numbers[0] << std::endl;
	std::cout << "Copy: " << copy[0] << std::endl;


	std::cout << GREEN "===== Test 5: Assigment operator =====" RESET << std::endl;
	Array<int> assigned;
	assigned = numbers;
	assigned[1] = 42;
	std::cout << "Original: " << numbers[1] << std::endl;
	std::cout << "Copy: " << assigned[1] << std::endl;

	std::cout << GREEN "===== Test 6: Write out of bounds =====" RESET << std::endl;
	try {
		numbers[42] = 42;
	} catch(std::exception &e){
		std::cout << "Limits error: " << e.what() << std::endl;
	}

	std::cout << GREEN "===== Test 7: Read out of bounds =====" RESET << std::endl;
	try {
		std::cout << numbers[8] << std::endl;
	} catch(std::exception &e){
		std::cout << "Limits error: " << e.what() << std::endl;
	}

	std::cout << GREEN "===== Test 8: String array =====" RESET << std::endl;
	Array<std::string> words(3);
	words[0] = "Hello";
	words[1] = "Hivers";
	words[2] = "8";
	for (unsigned int i = 0; i < words.size(); i++)
		std::cout << words[i] << " ";
	std::cout << std::endl;
	
	return 0;
}