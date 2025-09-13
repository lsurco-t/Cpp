#include "Contact.hpp"
#include <iostream>

Contact::Contact()
	 : _firstName(""), _lastName(""), _nickName(""), _phoneNumber(""), _darkestSecret("") {}
	
Contact::~Contact() {}


const std::string& Contact::getFirstName() const { 
	return _firstName; 
}

const std::string& Contact::getLastName() const { 
	return _lastName; 
}

const std::string& Contact::getNickName() const { 
	return _nickName; 
}

const std::string& Contact::getPhoneNumber() const {
	return _phoneNumber;
}

const std::string& Contact::getDarkestSecret() const {
	return _darkestSecret;
}


void Contact::setFirstName(const std::string& firstName) {
	 _firstName = firstName;
}

void Contact::setLastName(const std::string& lastName) {
	_lastName = lastName;
}

void Contact::setNickName(const std::string& nickName) {
	_nickName = nickName;
}

void Contact::setPhoneNumber(const std::string& phoneNumber) {
	_phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(const std::string& darkestSecret) {
	_darkestSecret = darkestSecret;
}