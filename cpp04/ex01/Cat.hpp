#pragma once
#include "Animal.hpp"
#include <iostream>

class Cat : public Animal {

	public:
		Cat();
		Cat(const Cat& other);
		Cat& operator=(const Cat& other);
		~Cat();

		void makeSound() const override;
};