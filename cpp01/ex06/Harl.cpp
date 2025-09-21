#include "Harl.hpp"

void Harl::debug(){
	std::cout << "[ DEBUG ]\n"
			  << "I just spent three hours aligning my Makefile so every tab is perfect. It looks amazing, trust me.\n\n";
}

void Harl::info(){
	std::cout << "[ INFO ]\n"
			  << "Why does Norminette care so much about spaces? I just wanted to add one more line, and boom — error!\n\n";
}

void Harl::warning(){
	std::cout << "[ WARNING ]\n"
			  << "I think I deserve some points back. The moulinette crashed during my defense!\n\n";
}

void Harl::error(){
	std::cout << "[ ERROR ]\n"
			  << "This is unacceptable! If my get_next_line segfaults one more time, I am dropping out of Hive!\n\n";
}

void Harl::complain(std::string level){
	typedef void (Harl::*levelFunctions)(void);
	std::string nameLevels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	levelFunctions arrayComplains[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	int index = -1;
	for (int i = 0; i < 4; i++){
		if (nameLevels[i] == level){
			index = i;
			break ;
		}
	}

	switch (index) {
		case 0: (this->*arrayComplains[0])();
				//fallthrough
		case 1: (this->*arrayComplains[1])();
				//fallthrough
		case 2: (this->*arrayComplains[2])();
				//fallthrough
		case 3: (this->*arrayComplains[3])();
			break;
		
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
	}
}