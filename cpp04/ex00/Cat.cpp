#include "Cat.hpp"

Cat::Cat(): Animal("Cat"){
	std::cout << "Cat's default constructor called\n";
}

Cat::Cat(const Cat& other): Animal(other){
	std::cout << "Cat's copy constructor called\n";
}

Cat& Cat::operator=(const Cat& other){
	if (this != &other){
		Animal::operator=(other);
	}
	std::cout << "Cat's copy assignment operator called\n";
	return *this;
}

Cat::~Cat(){
	std::cout << "Cat's destructor called\n";
}

void Cat::makeSound()const {
	std::cout << "Meowwwwwwwwwwwwwwwwww\n";
}
