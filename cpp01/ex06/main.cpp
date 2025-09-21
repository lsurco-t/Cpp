#include <iostream>
#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl hiverEight;

	if (argc != 2){
		std::cout << "Your complains can not be heard, enter a valid one!\n";
		return 1;
	}

	std::cout << "Hiver eight complain starts like: ";
	hiverEight.complain("INFO");
	std::cout << "\n";

	std::cout << "Hiver eight complain starts like: ";
	hiverEight.complain("ERROR");
	std::cout << "\n";
	
	return 0;
}