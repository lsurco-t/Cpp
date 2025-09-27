#include "Dog.hpp"

Dog::Dog(): AAnimal(), _dogBrain(new Brain){
	_type = "Dog";
	std::cout << "Dog's default constructor called\n";
}

Dog::Dog (const Dog& other): AAnimal(other){
	_dogBrain = new Brain(*other._dogBrain);
	std::cout << "Dog's copy constructor called \n";
}

Dog& Dog::operator=(const Dog& other){
	if (this != &other){
		AAnimal::operator=(other);
		delete _dogBrain;
		_dogBrain = new Brain(*other._dogBrain);
	}
	std::cout << "Dog's copy assignment operator called\n";
	return *this;
}

Dog::~Dog(){
	delete _dogBrain;
	std::cout << "Dog's destructor called\n";
}

void Dog::makeSound()const {
	std::cout << "Woooooffffffff Woofffffffff\n";
}
