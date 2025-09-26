#pragma once
#include "Animal.hpp"
#include <iostream>

class WrongAnimal : public Animal {

	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& other);
		WrongAnimal& operator=(const WrongAnimal& other);
		~WrongAnimal();

};