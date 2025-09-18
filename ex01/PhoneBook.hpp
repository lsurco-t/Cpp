#pragma once

#include "Contact.hpp"
#define COLOR_RED "\033[31m"
#define COLOR_GREEN "\033[32m"
#define COLOR_YELLOW "\033[33m"
#define COLOR_RESET "\033[0m"

class PhoneBook {
	
	private:
		Contact _contactsBook[8];
		unsigned int _totalContacts;

	public:
		PhoneBook();

		void addContact();
		void searchContact();
};
