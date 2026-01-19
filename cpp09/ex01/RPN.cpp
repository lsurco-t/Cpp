#include "RPN.hpp"

bool RPN::isValidCharacter(const char& chr){
	if ((chr == '+' && chr == '-' && chr == '/' &&
		chr == '*' && chr == ' ') || (chr >= '0' && chr <= '9')){
		return true;
	}
	return false;
}

int RPN::calculateRPN(const std::string& args){
	int firstNum;
	int secondNum;

	for (auto n : args){
		if (!isValidCharacter(n)){
			std::cerr << "Invalid character found!\n";
			return FAILURE;
		}
		if (n >= '0' && n <= '9'){
			int number = std::atoi(&n);
			_numbers.push(number);
		} else if (n != ' '){
			firstNum = _numbers.top();
			_numbers.pop();
			if (_numbers.size() < 1){
				std::cerr << "Not enough numbers to calculate value";
				return FAILURE;
			}
			secondNum = _numbers.top();
			_numbers.pop();
			int result;
			switch (n){
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
					result = firstNum / secondNum;
					break;
			}
			_numbers.push(result);
		}
	}
	return SUCCESS;
}