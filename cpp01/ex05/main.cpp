#include <iostream>
#include "Harl.hpp"

int main(void){

	Harl hiverEight;
	
	std::cout << "Hiver eight mode: ";
	hiverEight.complain("INFO");
	std::cout << "\n";

	std::cout << "Hiver eight mode: ";
	hiverEight.complain("DEBUG");
	std::cout << "\n";

	std::cout << "Hiver eight mode: ";
	hiverEight.complain("WARNING");
	std::cout << "\n";

	std::cout << "Hiver eight mode: ";
	hiverEight.complain("ERROR");
	std::cout << "\n";

	std::cout << "Hiver eight mode: ";
	hiverEight.complain("WHATEVER");
	std::cout << "\n";

	return 0;	
}