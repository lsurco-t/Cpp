#pragma once
#include "Contact.hpp"

class PhoneBook {
	
	private:
		Contact _contactsBook[8];
		unsigned int _totalContacts;

	public:
		PhoneBook();

		void addContact();
		void searchContact();
};
