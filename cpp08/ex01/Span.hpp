#pragma once
#include <climits>
#include <iostream>
#include <algorithm>
#include <random>
#include <vector>

class Span {

	private:
		std::vector<int> _numbers;
		unsigned int _maxSize;

	public:
		//Constructors and destructor
		Span() = delete;
		Span(int arraySize);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		//Member functions
		void addNumber(const int& element);
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;

		//Template function
		template<typename T>
		void addManyNumbers(T start, T end){
			if (_numbers.size() + std::distance(start, end) > _maxSize)
				throw fullContainer();
			for (T it = start; it != end; it++)
				addNumber(*it);
		}
		
		//Exception classes
		class emptyContainer : public std::exception {
			public:
				const char* what() const noexcept override;
		};

		class fullContainer : public std::exception {
			public:
				const char* what() const noexcept override;
		};
};