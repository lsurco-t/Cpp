#include <iostream>
#include "newZombieUtils.hpp"
#include "Zombie.hpp"

int main(void){

	randomChump("Foo");

	Zombie* zombieTwo = newZombie("Faa");
	std::cout << zombieTwo->getZombieName() << ": ";
	zombieTwo->announce();
	delete(zombieTwo);
	return (0);
}