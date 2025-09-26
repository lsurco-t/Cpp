#include "Dog.hpp"

Dog::Dog(){
	std::cout << "Dog's default constructor called\n";
}

Dog::Dog (const Dog& other){
	std::cout << "Dog's copy constructor called \n";
}

Dog& Dog::operator=(const Dog& other){
	std::cout << "Dog's copy assignment operator called\n";
}

Dog::~Dog(){
	std::cout << "Dog's destructor called\n";
}