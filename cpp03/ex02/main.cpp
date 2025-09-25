#include <iostream>
#include "FragTrap.hpp"

int main(void){

	FragTrap firstFragTrap("fragOne");
	FragTrap secondFragTrap("fragTwo");

	std::cout << "\n\033[31m------FIGHT------\033[0m\n";
	firstFragTrap.attack("Terminator");
	secondFragTrap.attack("Optimus");

	firstFragTrap.takeDamage(20);
	secondFragTrap.takeDamage(36);

	std::cout << "\n\033[31m------Other skills------\033[0m\n";
	firstFragTrap.beRepaired(40);
	secondFragTrap.beRepaired(30);

	firstFragTrap.highFivesGuys();

	return 0;
}