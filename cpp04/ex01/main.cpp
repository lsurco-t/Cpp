#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(){

	//Subject default's test
	std::cout << "\033[33m---------Subject Tests---------\033[0m\n";
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << "\033[31m-----Calling destructors-----\033[0m\n";
	delete i;
	delete j;
	delete meta;
	
	std::cout << "\n\033[33m---------Extra Tests---------\033[0m\n";

	const Animal* catOne = new Cat();
	const Animal* catTwo = new Cat();
	const WrongAnimal* wrongOne = new WrongCat();
	const WrongAnimal* wrongTwo = new WrongCat();
	const Animal* dogOne = new Dog();
	const Animal* dogTwo = new Dog();

	std::cout << catOne->getType() << " " << std::endl;
	std::cout << dogOne->getType() << " " << std::endl;
	std::cout << dogTwo->getType() << " " << std::endl;
	std::cout << wrongOne->getType() << " " << std::endl;

	catOne->makeSound();
	catTwo->makeSound();
	wrongOne->makeSound();
	wrongTwo->makeSound();
	dogOne->makeSound();
	dogTwo->makeSound();

	std::cout << "\033[31m-----Calling destructors-----\033[0m\n";
	delete catOne;
	delete catTwo;
	delete wrongOne;
	delete wrongTwo;
	delete dogOne;
	delete dogTwo;
	return 0;
}