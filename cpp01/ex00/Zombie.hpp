#pragma once

#include <iostream>

class Zombie {
	
	private:

		std::string _name;

	public:

		Zombie();
		~Zombie();

		void setZombieName(const std::string& zombieName);

		const std::string& getZombieName() const;

		void announce(void);
};