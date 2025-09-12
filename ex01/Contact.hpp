#pragma once

#include <string>

class Contact {
	private:
		std::string 	FirstName;
		std::string 	LastName;
		std::string 	Nickname;
		std::string		PhoneNumber;
		std::string 	DarkestSecret;
	public:
		Contact() = default;
		Contact(const Contact& other) = default;
		Contact& operator = (const Contact& other) = default;
		~Contact() = default;
};

