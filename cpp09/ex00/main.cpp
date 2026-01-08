#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>

int main(int argc, char **argv){
	if (argc != 2){
		std::cout << "Invalid number of arguments\n";
		return FAILURE;
	}
	try {
		BitcoinExchange newExchange;
		if (!newExchange.isValidFile(argv[1])){
			return FAILURE;
		}
	} catch (std::exception &e){
		std::cout << e.what() << '\n';	
	}
	return SUCCESS;
}
