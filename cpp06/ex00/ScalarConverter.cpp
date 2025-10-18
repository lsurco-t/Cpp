#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string& parameter){

	std::cout << std::fixed << std::setprecision(1);
	
	//Char conversion
	if (parameter.size() == 1 && !std::isdigit(parameter[0])){
		char charCheck = parameter[0];
		if (!std::isprint(static_cast<unsigned char>(charCheck)))
			std::cout << "Char: Non displayable" << std::endl;
		else
			std::cout << "Char: " << "'" << charCheck << "'" << std::endl;
	}
	else {
		try {
			int charRangeCheck = std::stoi(parameter);
			if (charRangeCheck < 0 || charRangeCheck > 127)
				std::cout << "Char: impossible" << std::endl;
			else if (!std::isprint(charRangeCheck))
				std::cout << "Char: Non displayable" << std::endl;
			else
				std::cout << "Char: " << "'" << static_cast<char>(charRangeCheck) << "'" << std::endl;
		} catch (std::exception &e){
			std::cout << "Char: impossible" << std::endl;
		}
	}

	//Int conversion
	try {
		long intCheck = std::stol(parameter);
		if (intCheck >= INT_MIN && intCheck <= INT_MAX)
			std::cout << "Int: " << static_cast<int>(intCheck) << std::endl;
		else
			std::cout << "Int: impossible" << std::endl;
	} catch (std::exception &e){
		std::cout << "Int: impossible" << std::endl;
	}

	//Float conversion
	try {
		double floatCheck =  std::stod(parameter);
		if (std::isinf(floatCheck) || std::isnan(floatCheck))
			std::cout << "Float: " << "f" << std::endl;
		else if (floatCheck >= -FLT_MAX && floatCheck <= FLT_MAX)
			std::cout << "Float: " << static_cast<float>(floatCheck) << std::endl;
		else
			std::cout << "Float: impossible" << std::endl;
	} catch (std::exception &e){
		std::cout << "Float: impossible" << std::endl;
	}

	//Double conversion
	try {
		double doubleCheck = std::stod(parameter);
		if (std::isinf(doubleCheck) || std::isnan(doubleCheck))
			std::cout << "Double: " << doubleCheck << std::endl;
		else if (doubleCheck >= -DBL_MAX && doubleCheck <= DBL_MAX)
			std::cout << "Double: " << doubleCheck << std::endl;
		else
			std::cout << "Double: impossible" << std::endl;
	} catch (std::exception &e){
		std::cout << "Double: impossible" << std::endl;
	}
}
