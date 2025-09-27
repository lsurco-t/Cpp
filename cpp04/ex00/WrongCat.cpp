#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal(){
	_type = "Duck";
	std::cout << "WrongCat's default constructor called\n";
}

WrongCat::WrongCat(const WrongCat& other): WrongAnimal(other){
	std::cout << "WrongCat's copy constructor called\n";
}

WrongCat& WrongCat::operator=(const WrongCat& other){
	if (this != &other)
		WrongAnimal::operator=(other);
	std::cout << "WrongCat's copy assignment operator called\n";
	return *this;
}

WrongCat::~WrongCat(){
	std::cout << "WrongCat's destructor called\n";
}

void WrongCat::makeSound() const {
	std::cout << "Brrrrrrrrrrrrr\n";
}
