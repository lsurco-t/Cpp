#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <iomanip>

void PhoneBook::addContact(){

	Contact newContact;
	std::string firstName, lastName, nickName, phoneNumber, darkestSecret;

	std::cout << "Enter a phone number: ";
	std::cin >> phoneNumber;
	
	newContact.setPhoneNumber (phoneNumber);
};

void PhoneBook::closePhoneBook() {
	
};

std::string getValidParam(const std::string& arg)
{
	std::string input = arg;

	do {
		std::cout << "Enter the information";
		std::cin >> input;
	}
	while (input.empty());

	return input;
}

int isValidNumber(std::string number)
{
	for (char c : number) {
		if (!std::isdigit(static_cast<unsigned char>(c))){
			std::cout << "Invalid number!\n";
			return (1);
		}
	}
	return (0);
}
