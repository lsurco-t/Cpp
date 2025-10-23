#pragma once
#include <iostream>
#include <algorithm>

class Span {

	private:
		unsigned int _elements;

	public:
		Span();
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		Span(int &element);
		void addNumber(const int& element) const;
		unsigned int shortestSpan();
		unsigned int longestSpan();
	
};