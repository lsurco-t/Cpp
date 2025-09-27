#pragma once
#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public Animal {

	private:
		Brain* _dogBrain;

	public:
		Dog();
		Dog (const Dog& other);
		Dog& operator=(const Dog& other);
		~Dog();

		void makeSound() const override;
};