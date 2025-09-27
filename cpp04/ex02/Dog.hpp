#pragma once
#include "AAnimal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public AAnimal {

	private:
		Brain* _dogBrain;

	public:
		Dog();
		Dog (const Dog& other);
		Dog& operator=(const Dog& other);
		~Dog();

		void makeSound() const override;
};