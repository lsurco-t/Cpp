#pragma once
#include <iostream>

class Ice{

	private:

	public:
		Ice();
		Ice(const Ice& other);
		Ice& operator=(const Ice& other);
		~Ice();
};