#include "Animal.hpp"

Animal::Animal(){
	std::cout << "Animal default constructor called\n";
}

Animal::Animal(const Animal& other){
	std::cout << "Animal copy constructor called\n";
}

Animal& Animal::operator=(const Animal& other){
	std::cout << "Animal copy operator overload called\n";
}

Animal::~Animal(){
	std::cout << "Animal destructor called\n";
}

std::string& Animal::getType()const{

}

void Animal::makeSound(){
	
}