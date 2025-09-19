#include "newZombieUtils.hpp"
#include "Zombie.hpp"

int main(void){

	randomChump("Foo");
	randomChump("Fii");
	randomChump("Fee");

	Zombie* zombieTwo = newZombie("Faa");
	zombieTwo->announce();
	delete zombieTwo;

	return 0;
}