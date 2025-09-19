#pragma once

#include <iostream>

class Zombie {
	
	private:

		std::string _name;

	public:

		Zombie();
		~Zombie();

		void setZombieName(const std::string& zombieName);

		void announce(void);
};