#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>

// General error codes return
constexpr int FAILURE = 1;
constexpr int SUCCESS = 0;

// Filename
constexpr const char* INPUT = "input.txt";

// Helpers


int main(int argc, char **argv){
	if (argc != 2){
		std::cout << "Invalid number of arguments\n";
		return FAILURE;
	}
	try {
		
	} catch (std::exception &e){
		std::cout << e.what() << '\n';	
	}
	return SUCCESS;
}
