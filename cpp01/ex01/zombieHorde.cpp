#include <iostream>
#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ){

	if (N <= 0)
		return nullptr;

	Zombie* newZombieHorde = new Zombie[N];
	for (int i = 0; i < N; i++){
		newZombieHorde[i].setZombieName(name);
	}
	return newZombieHorde;
}