#pragma once
#include <climits>
#include <iostream>
#include <string>
#include <cfloat>
#include <cmath>
#include <iomanip>

class ScalarConverter {

	private:
		ScalarConverter() = delete;
		ScalarConverter(const ScalarConverter& other) = delete;
		ScalarConverter& operator=(const ScalarConverter& other) = delete;
		~ScalarConverter() = delete;

	public:
		static void convert(const std::string& parameter);
};