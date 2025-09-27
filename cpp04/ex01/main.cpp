#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(){

	//Subject default's test
	std::cout << "\033[33m---------Subject Tests---------\033[0m\n";
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "\033[31m-----Calling destructors-----\033[0m\n";
	delete j;//should not create a leak
	delete i;

	//Own tests
	std::cout << "\n\033[33m---------Extra Tests---------\033[0m\n";
	

	std::cout << "\033[31m-----Calling destructors-----\033[0m\n";
	
	return 0;
}