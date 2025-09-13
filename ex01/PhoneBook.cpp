#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

void addContact(){

	Contact newContact;
	std::string number;

	std::cin >> number;
	for (char c : number) {
		if (!std::isdigit(static_cast<unsigned char>(c))){
			std::cout << "Invalid number!\n";
			return ;
		}
	}
	newContact.setPhoneNumber (number);
}; 