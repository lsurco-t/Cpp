#include "ScalarConverter.hpp"

#define SUCCESS 0
#define FAILURE 1

int main(int argc, char **argv){

	if (argc != 2){
		std::cout << "Invalid number of arguments!" << std::endl;
		return FAILURE;
	}
	try{
		ScalarConverter::convert(argv[1]);
	}
	catch (const std::exception &e){
		std::cout << e.what() << std::endl;
		return FAILURE;
	}
	return SUCCESS;
}
