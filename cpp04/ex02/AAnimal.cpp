#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("Default AAnimal"){
	std::cout << "AAnimal default constructor called\n";
}

AAnimal::AAnimal(const AAnimal& other) : _type(other._type){
	std::cout << "AAnimal copy constructor called\n";
}

AAnimal& AAnimal::operator=(const AAnimal& other){
	if (this != &other)
		_type = other._type;
	std::cout << "AAnimal copy assignment operator called\n";
	return *this;
}

AAnimal::~AAnimal(){
	std::cout << "AAnimal destructor called\n";
}

const std::string& AAnimal::getType()const{
	return _type;
}

void AAnimal::makeSound()const{
	std::cout << "This is a generic AAnimal without sound\n";
}