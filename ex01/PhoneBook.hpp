#pragma once
#include "Contact.hpp"

class PhoneBook {
	private:
		Contact _contactsBook[8];

	public:

		PhoneBook() = default;
		~PhoneBook() = default;
		
		void addContact();
		void searchContact();
		void closePhoneBook();
};
