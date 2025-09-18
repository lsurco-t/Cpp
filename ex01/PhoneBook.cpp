#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <limits>

PhoneBook::PhoneBook() : _totalContacts(0) {}

bool isValidNumber(std::string& number){
	
	for (char c : number) {
		if (!std::isdigit(static_cast<unsigned char>(c))){
			std::cout << COLOR_RED << "Invalid number!\n" << COLOR_RESET;
			return (false);
		}
	}
	return (true);
}

std::string getValidParam(const std::string& prompt){
	
	std::string input;

	do {
		std::cout << prompt << ": ";
		if (!std::getline(std::cin, input)) {
			std::cout << COLOR_RED << ("Failed to read input.\n") << COLOR_RESET;
			std::exit(0);
		}
		if (input.empty()) {
			std::cout << COLOR_RED << "Input can not be empty!\n" << COLOR_RESET;
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
}

std::string truncateField(const std::string& str){
	if (str.length() > 10) {
		return str.substr(0, 9) + ".";
	}
	return str;
}

void PhoneBook::searchContact(){
	
		if (_totalContacts == 0) {
			std::cout << COLOR_RED << "No contacts available." << COLOR_RESET << std::endl;
			return ;
		}

		std::cout << "|" << COLOR_YELLOW << std::setw(10) << "Index" << COLOR_RESET;
		std::cout << "|" << COLOR_YELLOW << std::setw(10) << "First Name" << COLOR_RESET;
		std::cout << "|" << COLOR_YELLOW << std::setw(10) << "Last Name" << COLOR_RESET;
		std::cout << "|" << COLOR_YELLOW << std::setw(10) << "Nickname" << COLOR_RESET << "|" << std::endl;

		int maxContacts = (_totalContacts < 8) ? _totalContacts : 8;
		int start = (_totalContacts >=8) ? (_totalContacts % 8) : 0;

		for (int i = 0; i < maxContacts; i++) {
			int realIndex = (start + i) % 8;
			std::cout << "|" << std::setw(10) << i;
			std::cout << "|" << std::setw(10) << truncateField(_contactsBook[realIndex].getFirstName());
			std::cout << "|" << std::setw(10) << truncateField(_contactsBook[realIndex].getLastName());
			std::cout << "|" << std::setw(10) << truncateField(_contactsBook[realIndex].getNickName()) << "|" << std::endl;
		}

		int index = 0;
		std::cout << "Select user index to display: ";
		if (!(std::cin >> index) || index < 0 || index >= maxContacts) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << COLOR_RED << "Invalid index number." << COLOR_RESET << std::endl;
			return ;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		int realIndex = (start + index) % 8;

		std::cout << COLOR_YELLOW << "First name: " << COLOR_RESET << _contactsBook[realIndex].getFirstName() << std::endl;
		std::cout << COLOR_YELLOW << "Last name : " << COLOR_RESET << _contactsBook[realIndex].getLastName() << std::endl;
		std::cout << COLOR_YELLOW << "Nickname  : " << COLOR_RESET << _contactsBook[realIndex].getNickName() << std::endl;
		std::cout << COLOR_YELLOW << "Phone number : " << COLOR_RESET << _contactsBook[realIndex].getPhoneNumber() << std::endl;
		std::cout << COLOR_YELLOW << "Darkest secret : " << COLOR_RESET << _contactsBook[realIndex].getDarkestSecret() << std::endl;
}
