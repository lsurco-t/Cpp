#include "Animal.hpp"

Animal::Animal(){
	std::cout << "Animal default constructor called\n";
}

Animal::Animal(const Animal& other){
	std::cout << "Animal copy constructor called\n";
}

Animal& Animal::operator=(const Animal& other){
	std::cout << "Animal copy assignment operator called\n";
}

Animal::~Animal(){
	std::cout << "Animal destructor called\n";
}

const std::string& Animal::getType()const{
	return _type;
}

void Animal::makeSound() const {
	std::cout << "This is a generic animal without sound\n";
}