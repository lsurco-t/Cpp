#include <iostream>
#include "Zombie.hpp"

Zombie* newZombie(std::string name){

	Zombie newZombie;

	std::cout << name << ": " << std::endl;
	newZombie.setZombieName(name);
	newZombie.announce();	
}

