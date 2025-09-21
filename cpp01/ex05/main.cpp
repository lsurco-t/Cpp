#include <iostream>
#include "Harl.hpp"

int main(void){

	Harl hiverEight;
	
	std::cout << "Hiver eight says: ";
	hiverEight.complain("INFO");
	std::cout << "\n";

	std::cout << "Hiver eight says: ";
	hiverEight.complain("DEBUG");
	std::cout << "\n";

	std::cout << "Hiver eight says: ";
	hiverEight.complain("WARNING");
	std::cout << "\n";

	std::cout << "Hiver eight says: ";
	hiverEight.complain("ERROR");
	std::cout << "\n";

	std::cout << "Hiver eight says: ";
	hiverEight.complain("WHATEVER");
	std::cout << "\n";

	return 0;	
}