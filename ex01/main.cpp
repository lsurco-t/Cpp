#include <iostream>
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
		std::getline(std::cin, option);

		if (option == "ADD") {
			newBook.addContact();
		}
		else if (option == "SEARCH"){
			std::cout << "Here are the contacts\n";
			newBook.searchContact();
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
