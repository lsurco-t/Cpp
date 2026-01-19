#pragma once
#include <stack>
#include <string>
#include <algorithm>
#include <iostream>

// General error codes return
constexpr int FAILURE = 1;
constexpr int SUCCESS = 0;

class RPN {
	
	private:
		std::stack<int, int> _numbers;

	public:
		RPN() = default;
		RPN(const RPN& other) = delete;
		RPN& operator=(const RPN& other) = delete;
		~RPN() = default;

		bool isValidCharacter(const char& c);
		int calculateRPN(const std::string& args);
};