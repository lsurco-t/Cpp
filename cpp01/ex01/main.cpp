#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main(void){

	int N = 5;

	Zombie* horde = zombieHorde(N, "Hiver 8");

	for (int i = 0; i < N; i++){
		horde[i].announce();
	}
	delete[] horde;

	return 0;
}