#include <iostream>
#include <iomanip>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int	main(void)
{
	char option;

	do {
		std::cout << "********************************\n";
		std::cout << "\033[33m    Welcome to the Phonebook\033[0m\n";
		std::cout << "********************************\n";
		std::cout << "1. ADD\n";
		std::cout << "2. SEARCH\n";
		std::cout << "3. EXIT\n";
		std::cout << "\033[31mPlease select an action\033[0m\n";
		std::cin >> option;

		switch(option) {
			case '1':
				break;
			case '2':
				break;
			case '3':
				std::cout << "See you soon!\n";
				break;
			default:
				std::cout << "Invalid number!\n";
				break;
		}
	} while (option != '3');
	
	return 0;
}
