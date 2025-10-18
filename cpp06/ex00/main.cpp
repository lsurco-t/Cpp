#include "ScalarConverter.hpp"

#define SUCCESS 0
#define FAILURE 1

int main(int argc, char **argv){

	if (argc != 2){
		std::cout << "\033[31mInvalid number of arguments!\033[0m" << std::endl;
		return FAILURE;
	}
	std::cout << "\033[32m======WELCOME TO USE THE GREAT CONVERTER======\033[0m" << std::endl;
	ScalarConverter::convert(argv[1]);
	return SUCCESS;
}
