#include "Cat.hpp"

Cat::Cat(): AAnimal(), _catBrain(new Brain){
	_type = "Cat";
	std::cout << "Cat's default constructor called\n";
}

Cat::Cat(const Cat& other): AAnimal(other){
	_catBrain = new Brain(*other._catBrain);
	std::cout << "Cat's copy constructor called\n";
}

Cat& Cat::operator=(const Cat& other){
	if (this != &other){
		AAnimal::operator=(other);
		delete _catBrain;
		_catBrain = new Brain(*other._catBrain);
	}
	std::cout << "Cat's copy assignment operator called\n";
	return *this;
}

Cat::~Cat(){
	delete _catBrain;
	std::cout << "Cat's destructor called\n";
}

void Cat::makeSound()const {
	std::cout << "Meowwwwwwwwwwwwwwwwww\n";
}
