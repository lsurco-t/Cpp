#pragma once
#include <stack>

class RPN {
	
	private:
		std::stack<int, int> _numbers;

	public:
		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();

		bool isValidCharacter();
};