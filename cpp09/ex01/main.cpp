#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv){
	if (argc != 2){
		std::cerr << "Invalid number of arguments, pass arg in quotes\n";
		return FAILURE;
	}
	RPN newRPN;
	if (newRPN.calculateRPN(argv[1]) == FAILURE){
		return FAILURE;
	}
	return SUCCESS;
}