#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : _totalContacts(0) {}

bool isValidNumber(std::string& number) {
	
	for (char c : number) {
		if (!std::isdigit(static_cast<unsigned char>(c))){
			std::cout << "\033[31mInvalid number!\033[0m\n";
			return (false);
		}
	}
	return (true);
}

std::string getValidParam(const std::string& prompt) {
	
	std::string input;

	do {
		std::cout << prompt << ": ";
		if (!std::getline(std::cin, input)) {
			throw std::runtime_error("Failed to read input");
		}
		if (input.empty()) {
			std::cout << "\033[31mInput can not be empty!\033[0m\n";
		}
	} while (input.empty());
	return (input);
}

void PhoneBook::addContact() {

	Contact newContact;
	std::string firstName, lastName, nickName, phoneNumber, darkestSecret;

	firstName = getValidParam ("Enter first name");
	lastName = getValidParam ("Enter last name");
	nickName = getValidParam ("Enter nickname");

	do {
		phoneNumber = getValidParam ("Enter phone number");
	} while (!isValidNumber(phoneNumber));

	darkestSecret = getValidParam ("Enter darkest secret");

	newContact.setFirstName (firstName);
	newContact.setLastName (lastName);
	newContact.setNickName (nickName);
	newContact.setPhoneNumber (phoneNumber);
	newContact.setDarkestSecret (darkestSecret);

	unsigned int index = _totalContacts % 8;
	_contactsBook[index] = newContact;
	_totalContacts++;
	std::cout << "contact added at index " << index << std::endl; //debugging line
}

void searchContact() {
	
}


