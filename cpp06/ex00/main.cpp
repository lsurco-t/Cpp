#include "ScalarConverter.hpp"

int main(int argc, char **argv){

	if (argc != 2){
		std::cout << "Invalid number of arguments!" << std::endl;
		return 0;
	}
	try{
		std::string valueToConvert = argv[1];
		ScalarConverter::convert(valueToConvert);
	}
	catch (const std::exception &e){
		std::cout << e.what() << std::endl;
	}
	return 0;
}