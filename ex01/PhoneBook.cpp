#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <iomanip>

bool isValidNumber(std::string number)
{
	for (char c : number) {
		if (!std::isdigit(static_cast<unsigned char>(c))){
			std::cout << "Invalid number!\n";
			return (false);
		}
	}
	return (true);
}

std::string getValidParam(const std::string& prompt)
{
	std::string input;

	do {
		std::cout << prompt << ": ";
		std::cin >> input;
		if (input.empty()) {
			std::cout << "Input can not be empty!\n";
		}
	} while (input.empty());

	return (input);
}

void PhoneBook::addContact(){

	Contact newContact;
	std::string firstName, lastName, nickName, phoneNumber, darkestSecret;

	firstName = getValidParam ("Enter first name");
	lastName = getValidParam ("Enter last name");
	nickName = getValidParam ("Enter nickname");
	phoneNumber = getValidParam ("Enter phone number");
	darkestSecret = getValidParam ("Enter darkest secret");

	newContact.setFirstName (firstName);
	newContact.setLastName (lastName);
	newContact.setNickName (nickName);
	newContact.setPhoneNumber (phoneNumber);
	newContact.setDarkestSecret (darkestSecret);
};

