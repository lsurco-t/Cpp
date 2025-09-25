#include <iostream>
#include "ClapTrap.hpp"

int main(void){

	ClapTrap nameBot("Robocop");
	ClapTrap nameBotTwo("Optimus");

	ClapTrap copyBot(nameBot);

	ClapTrap assignedBot;
	assignedBot = nameBotTwo;

	std::cout << "\n\033[31m------FIGHT!------\033[0m\n";

	nameBot.attack("Enemy");
	copyBot.attack("Enemy");

	std::cout << "\n\033[31mClapTrap takes damage!\033[0m\n";
	nameBot.takeDamage(5);
	nameBot.takeDamage(10);

	std::cout << "\n\033[31mTesting when ran out of points\033[0m\n";
	copyBot.beRepaired(3);
	copyBot.takeDamage(20);
	copyBot.beRepaired(5);

	std::cout << "\n\033[31mRapid attack 15 times!\033[0m\n";
	for (int i = 0; i < 15; i++)
		nameBotTwo.attack("anotherBot");
    
	std::cout << "\n\033[31m--- Destruction Order ---\033[0m\n";
	return 0;
}