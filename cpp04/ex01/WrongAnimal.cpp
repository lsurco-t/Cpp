#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): _type("default"){
	std::cout << "WrongAnimal's default constructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other): _type(other._type) {
	std::cout << "WrongAnimal's copy constructor called\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other){
	if (this != &other)
		_type = other._type;
	std::cout << "WrongAnimal's copy assignment operator called\n";
	return *this;
}

WrongAnimal::~WrongAnimal(){
	std::cout << "WrongAnimal's destructor called\n";
}

const std::string& WrongAnimal::getType()const{
	return _type;
}

void WrongAnimal::makeSound() const {
	std::cout << "Cuackkkkkkkkkkkkkkkk\n";
}