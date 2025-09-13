#pragma once
#include "Contact.hpp"

class PhoneBook {
	private:
		Contact _contactsBook[8];

	public:
		
		void addContact();
		void searchContact();
		void closePhoneBook();
};
