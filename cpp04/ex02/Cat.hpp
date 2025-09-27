#pragma once
#include "A_Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat : public A_Animal {

	private:
		Brain* _catBrain;
		
	public:
		Cat();
		Cat(const Cat& other);
		Cat& operator=(const Cat& other);
		~Cat();

		void makeSound() const override;
};