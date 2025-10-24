#include "Span.hpp"

Span::Span(const Span& other): _numbers(other._numbers), _maxSize(other._maxSize){}	

Span&  Span::operator=(const Span& other){
	if (this != &other){
		_numbers = other._numbers;
		_maxSize = other._maxSize;		
	}
	return *this;
}

Span::~Span(){}

Span::Span(int arraySize) : _numbers(), _maxSize(arraySize){}

void Span::addNumber(const int& element){
	if (_numbers.size() >= _maxSize)
		throw fullContainer();
	_numbers.push_back(element);
}

unsigned int Span::shortestSpan() const {
	if (_numbers.size() < 2)
		throw emptyContainer();

	std::vector<int> tempVector	= _numbers;
	std::sort(tempVector.begin(), tempVector.end());

	unsigned int result = UINT_MAX;
	for(size_t i = 0; i < tempVector.size() - 1; i++){
		unsigned int diff = tempVector[i + 1] - tempVector[i];
		if (diff < result)
		result = diff;
	}
	return result;
}

unsigned int Span::longestSpan() const {
	if (_numbers.size() < 2)
		throw emptyContainer();

	int min = *std::min_element(_numbers.begin(), _numbers.end());
	int max = *std::max_element(_numbers.begin(), _numbers.end());
	
	return static_cast<unsigned int>(max - min);
}

const char* Span::emptyContainer::what() const noexcept {
	return "This container is empty or has only 1 number!";
}

const char* Span::fullContainer::what() const noexcept {
	return "This container is full!";
}