#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string& parameter){

	std::cout << std::fixed << std::setprecision(1);

	//Char conversion
	if (parameter.size() == 1 && !std::isdigit(parameter[0])){
		char charCheck = parameter[0];
		if (!std::isprint(static_cast<unsigned char>(charCheck)))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: " << "'" << charCheck << "'" << std::endl;
	}
	else {
		try {
			int charRangeCheck = std::stoi(parameter);
			if (charRangeCheck < 0 || charRangeCheck > 127)
				std::cout << "char: impossible" << std::endl;
			else if (!std::isprint(charRangeCheck))
				std::cout << "char: Non displayable" << std::endl;
			else
				std::cout << "char: " << "'" << static_cast<char>(charRangeCheck) << "'" << std::endl;
		} catch (std::exception &e){
			std::cout << "char: impossible" << std::endl;
		}
	}

	//Int conversion
	try {
		long intCheck = std::stol(parameter);
		if (intCheck >= INT_MIN && intCheck <= INT_MAX)
			std::cout << "int: " << static_cast<int>(intCheck) << std::endl;
		else
			std::cout << "int: impossible" << std::endl;
	} catch (std::exception &e){
		std::cout << "int: impossible" << std::endl;
	}

	//Float conversion
	try {
		double floatCheck =  std::stod(parameter);
		if (std::isnan(floatCheck))
			std::cout << "float: nanf" << std::endl;
		else if (std::isinf(floatCheck))
			std::cout << "float: " << (floatCheck < 0 ? "-inff" : "inff") << std::endl;
		else if (floatCheck > FLT_MAX || floatCheck < -FLT_MAX)
			std::cout << "float: impossible" << std::endl;
		else
			std::cout << "float: " << static_cast<float>(floatCheck) << "f" << std::endl;
	} catch (std::exception &e){
		std::cout << "float: impossible" << std::endl;
	}

	//Double conversion
	try {
		double doubleCheck = std::stod(parameter);
		if (std::isnan(doubleCheck))
			std::cout << "double: nan" << std::endl;
		else if (std::isinf(doubleCheck))
			std::cout << "double: " << (doubleCheck < 0 ? "-inf" : "inf") << std::endl;
		else
			std::cout << "double: " << doubleCheck << std::endl;
	} catch (std::exception &e){
		std::cout << "double: impossible" << std::endl;
	}
}
