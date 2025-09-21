#include <iostream>
#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl hiverEight;

	if (argc != 2){
		std::cout << "\033[31mYour complains can not be heard, enter a valid one!\n\033[0m";
		return 1;
	}

	std::cout << "\033[31mHiver eight mode: \033[0m";
	hiverEight.complain(argv[1]);
	std::cout << "\n";

	std::cout << "\033[31mHiver eight mode: \033[0m";
	hiverEight.complain(argv[1]);
	std::cout << "\n";

	return 0;
}