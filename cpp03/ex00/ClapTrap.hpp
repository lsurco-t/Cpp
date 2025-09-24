#pragma once
#include <iostream>

class ClapTrap {

	private:
		unsigned int hitPoints = 10;
		unsigned int energyPoints = 10;
		unsigned int attackDamage = 0;
		ClapTrap(std::string name);

	public:
		ClapTrap();
		ClapTrap (const ClapTrap& other);
		ClapTrap& operator=(const ClapTrap& other);
		~ClapTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};