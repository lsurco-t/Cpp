#include "A_Animal.hpp"

A_Animal::A_Animal() : _type("Default A_Animal"){
	std::cout << "A_Animal default constructor called\n";
}

A_Animal::A_Animal(const A_Animal& other) : _type(other._type){
	std::cout << "A_Animal copy constructor called\n";
}

A_Animal& A_Animal::operator=(const A_Animal& other){
	if (this != &other)
		_type = other._type;
	std::cout << "A_Animal copy assignment operator called\n";
	return *this;
}

A_Animal::~A_Animal(){
	std::cout << "A_Animal destructor called\n";
}

const std::string& A_Animal::getType()const{
	return _type;
}

void A_Animal::makeSound()const{
	std::cout << "This is a generic A_Animal without sound\n";
}