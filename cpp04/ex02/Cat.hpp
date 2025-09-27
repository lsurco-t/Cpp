#pragma once
#include "AAnimal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat : public AAnimal {

	private:
		Brain* _catBrain;
		
	public:
		Cat();
		Cat(const Cat& other);
		Cat& operator=(const Cat& other);
		~Cat();

		void makeSound() const override;
};