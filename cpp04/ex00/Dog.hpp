#pragma once
#include <iostream>

class Dog : public Animal{

	public:
		Dog();
		Dog (const Dog& other);
		Dog& operator=(const Dog& other);
		~Dog();
};