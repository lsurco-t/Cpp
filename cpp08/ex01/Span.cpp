#include "Span.hpp"

Span::Span(){}

Span::Span(const Span& other){}	

Span&  Span::operator=(const Span& other){
	return *this;
}

Span::~Span(){}

Span::Span(int arraySize){

}

void Span::addNumber(const int& element){

}

unsigned int Span::shortestSpan() const {

}

unsigned int Span::longestSpan() const {

}

const char* Span::emptyContainer::what() const noexcept {
	return "This container is empty!";
}

const char* Span::fullContainer::what() const noexcept {
	return "This container is full!";
}