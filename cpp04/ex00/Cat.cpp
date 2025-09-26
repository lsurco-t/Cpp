#include "Cat.hpp"

Cat::Cat(){
	std::cout << "Cat's default constructor called\n";
}

Cat::Cat(const Cat& other){
	std::cout << "Cat's copy operator called\n";
}

Cat& Cat::operator=(const Cat& other){
	std::cout << "Cat's copy assignment operator called\n";
}

Cat::~Cat(){
	std::cout << "Cat's destructor called\n";
}