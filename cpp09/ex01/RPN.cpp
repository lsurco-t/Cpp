#include "RPN.hpp"

bool RPN::isValidToken(const std::string& token){
	return token[0] == '*' || token[0] == '+' || token[0] == '-' || token[0] == '/'; 
}

int RPN::calculateRPN(const std::string& args){
	std::istringstream iss(args);
	std::string token;

	while (iss >> token){
		int number = 0;
		if (token.find_first_not_of("-0123456789") == std::string::npos && token != "-"
				&& !token.empty()){
			try {
				number = std::stoi(token);
				if (number > 9){
					std::cerr << "Error: Invalid number: " << number << std::endl;
					return FAILURE;
				}
				_numbers.push(number);
			} catch (...){
				std::cerr << "Error: Invalid number: " << number << std::endl;
				return FAILURE;
			}
		}
		else if (token.length() == 1 && isValidToken(token)){
			int firstNum = 0;
			int secondNum = 0;
			if (_numbers.size() < 2){
				std::cerr << "Error: Not enough numbers to calculate value\n";
				return FAILURE;
			}
			secondNum = _numbers.top();
			_numbers.pop();
			firstNum = _numbers.top();
			_numbers.pop();
			int result = 0;
			switch (token[0]){
				case '*':
					result = firstNum * secondNum;	
					break;
				case '+':
					result = firstNum + secondNum;
					break;
				case '-':
					result = firstNum - secondNum;
					break;
				case '/':
					if (secondNum == 0){
						std::cerr << "Error: division by zero\n";
						return FAILURE;
					}
					result = firstNum / secondNum;
					break;
			}
			_numbers.push(result);
		} else {
			std::cerr << "Error: invalid token: " << token << std::endl;
			return FAILURE;
		}
	}
	if (_numbers.size() != 1){
		std::cerr << "Error: invalid expression\n";
		return FAILURE;
	}
	std::cout << _numbers.top() << std::endl;
	return SUCCESS;
}