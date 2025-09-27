#include "Animal.hpp"

Animal::Animal() : _type("Default animal"){
	std::cout << "Animal default constructor called\n";
}

Animal::Animal(const Animal& other) : _type(other._type){
	std::cout << "Animal copy constructor called\n";
}

Animal& Animal::operator=(const Animal& other){
	if (this != &other)
		_type = other._type;
	std::cout << "Animal copy assignment operator called\n";
	return *this;
}

Animal::~Animal(){
	std::cout << "Animal destructor called\n";
}

const std::string& Animal::getType()const{
	return _type;
}

void Animal::makeSound()const{
	std::cout << "This is a generic animal without sound\n";
}