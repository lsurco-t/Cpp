#pragma once
#include <iostream>

class AAnimal{

	protected:
		std::string _type;

	public:
		AAnimal();
		AAnimal(const AAnimal& other);
		AAnimal& operator=(const AAnimal& other);
		virtual ~AAnimal();

		const std::string& getType()const;
		virtual void makeSound() const = 0;
};