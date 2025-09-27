#include <iostream>
#include "A_Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(){

	//Subject default's test
	std::cout << "\033[33m---------Subject Tests---------\033[0m\n";
	const A_Animal* j = new Dog();
	const A_Animal* i = new Cat();

	std::cout << "\033[31m-----Calling destructors-----\033[0m\n";
	delete j;//should not create a leak
	delete i;

	//Own tests
	std::cout << "\n\033[33m---------Extra Tests---------\033[0m\n";
	size_t amount = 10;
	A_Animal* zoo[amount];
	for (size_t i = 0; i < amount; i++){	
		if (i < (amount / 2))
			zoo[i] = new Dog();
		else
			zoo[i] = new Cat();
	}
	for (size_t i = 0; i < amount; i++){
		zoo[i]->makeSound();
	}
	std::cout << "\033[31m-----Calling destructors-----\033[0m\n";
	for (size_t i = 0; i < amount; i ++)
		delete zoo[i] ;
	return 0;
}