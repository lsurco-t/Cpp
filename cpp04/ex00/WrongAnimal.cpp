#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
	std::cout << "WrongAnimal's default constructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other){
	std::cout << "WrongAnimal's copy constructor called\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other){
	std::cout << "WrongAnimal's copy assignment operator called\n";
}

WrongAnimal::~WrongAnimal(){
	std::cout << "WrongAnimal's destructor called\n";
}