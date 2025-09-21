#include "Harl.hpp"

void Harl::debug(){
	std::cout << "[ DEBUG ]\n"
			  << "I just spent three hours aligning my Makefile so every tab is perfect. It looks amazing, trust me.\n";
}

void Harl::info(){
	std::cout << "[ INFO ]\n"
			  << "Why does Norminette care so much about spaces? I just wanted to add one more line, and boom — error!\n";
}

void Harl::warning(){
	std::cout << "[ WARNING ]\n"
			  << "I think I deserve some points back. The moulinette crashed during my defense!\n";
}

void Harl::error(){
	std::cout << "[ ERROR ]\n"
			  << "This is unacceptable! If my get_next_line segfaults one more time, I am dropping out of Hive!\n";
}

void Harl::complain(std::string level){
	typedef void (Harl::*levelFunctions)(void);
	std::string nameLevels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	levelFunctions arrayComplains[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < 4; i++){
		if (nameLevels[i] == level){
			(this->*arrayComplains[i])();
			return ;
		}
	}
	std::cout << "[ Probably complaining about insignificant problems ]\n";
}