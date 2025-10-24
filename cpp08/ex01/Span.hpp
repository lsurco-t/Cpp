#pragma once
#include <iostream>
#include <algorithm>
#include <random>

class Span {

	private:
		std::vector<int> _numbers;
		unsigned int _maxSize;

	public:
		Span();
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		Span(int arraySize);
		void addNumber(const int& element);
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;

		class emptyContainer : public std::exception {
			public:
				const char* what() const noexcept override;
		};

		class fullContainer : public std::exception {
			public:
				const char* what() const noexcept override;
		};
};