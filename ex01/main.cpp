#include <iostream>
#include <limits>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook newBook;
	std::string option;

	std::cout << "*******************************************\n";
	std::cout << "\033[33m    Welcome to the great Phonebook\033[0m\n";
	std::cout << "*******************************************\n";
	
	while (true)
	{
		std::cout << "\033[32mType ADD, SEARCH or EXIT, nothing else!!\033[0m\n";
		if (!std::getline(std::cin, option)) {
			std::cout << "\033[31mGoodbye!\033[0m\n";
			break;;
		}
		if (option == "ADD"){
			newBook.addContact();
		}
		else if (option == "SEARCH"){
			newBook.searchContact();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		}
		else if (option == "EXIT"){
			std::cout << "\033[31mGoodbye!\033[0m\n";
			break;
		}
		else
			std::cout << "\033[30mInvalid option!\033[0m\n";
	}
	return 0;
}
