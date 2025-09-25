#include <iostream>
#include "ScavTrap.hpp"

int main(void){

	ScavTrap robotone("robotOne");
	ScavTrap robottwo("robotTwo");
	ScavTrap robotthree("robotThree");

	std::cout << "\n\033[31m------FIGHT------\033[0m\n";
	robotone.attack("robotTwo");
	robotone.takeDamage(10);

	std::cout << "\n\033[31m---Fight moreeee---\033[0m\n";
	robotthree.attack("robotin");
	robottwo.guardGate();

	std::cout << "\n\033[31m---Other Skills---\033[0m\n";
	robotthree.beRepaired(5);
	robottwo.guardGate();

	std::cout << "\n\033[31m---Fast Attack---\033[0m\n";
	for (int i = 0; i < 3; i++)
		robotthree.takeDamage(40);
		
	return 0;
}