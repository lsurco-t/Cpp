#include <iostream>
#include "Zombie.hpp"

void randomChump(std::string name){
	
	Zombie newZombieStack;

	newZombieStack.setZombieName(name);
	std::cout << newZombieStack.getZombieName() << ": ";
	newZombieStack.announce();
}