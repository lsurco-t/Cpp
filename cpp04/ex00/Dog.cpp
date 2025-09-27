#include "Dog.hpp"

Dog::Dog(): Animal(){
	_type = "Dog";
	std::cout << "Dog's default constructor called\n";
}

Dog::Dog (const Dog& other): Animal(other){
	std::cout << "Dog's copy constructor called \n";
}

Dog& Dog::operator=(const Dog& other){
	if (this != &other)
		Animal::operator=(other);
	std::cout << "Dog's copy assignment operator called\n";
	return *this;
}

Dog::~Dog(){
	std::cout << "Dog's destructor called\n";
}

void Dog::makeSound()const {
	std::cout << "Woooooffffffff Woofffffffff\n";
}
