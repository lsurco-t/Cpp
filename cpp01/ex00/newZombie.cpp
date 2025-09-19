#include <iostream>
#include "Zombie.hpp"

Zombie* newZombie(std::string name){

	Zombie* newZombieHeap = new Zombie();
	newZombieHeap->setZombieName(name);
	return newZombieHeap;
}
