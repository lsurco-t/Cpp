#pragma once
#include <iostream>

class Animal{

	private:
		std::string _type;

	public:
		Animal();
		Animal(const std::string& type);
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		virtual ~Animal();

		const std::string& getType()const;
		virtual void makeSound() const;
};