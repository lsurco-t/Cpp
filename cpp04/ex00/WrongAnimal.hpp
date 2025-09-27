#pragma once
#include <iostream>

class WrongAnimal {

	private:
		std::string _type;

	public:
		WrongAnimal();
		WrongAnimal(const std::string& type);
		WrongAnimal(const WrongAnimal& other);
		WrongAnimal& operator=(const WrongAnimal& other);
		virtual ~WrongAnimal();

		const std::string& getType()const;
		virtual void makeSound() const;
};