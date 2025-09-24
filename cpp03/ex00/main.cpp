#include <iostream>
#include "ClapTrap.hpp"

int main(void){

	ClapTrap defaultBot;
	ClapTrap nameBot("Robo");

	ClapTrap copyBot(nameBot);

	ClapTrap assignedBot;
	assignedBot = defaultBot;

	std::cout << "\n\033[31m------FIGHT!------\033[0m\n";

	nameBot.attack("Enemy");
	copyBot.attack("Enemy");

	nameBot.takeDamage(5);
	nameBot.takeDamage(10);

	copyBot.beRepaired(3);
	copyBot.takeDamage(20);
	copyBot.beRepaired(5);

	for (int i = 0; i < 15; i++)
		defaultBot.attack("anotherBot");
		
	return 0;
}