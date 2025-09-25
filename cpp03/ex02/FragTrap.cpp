#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap(){
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "Fragtrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap (const FragTrap& other) : ClapTrap(other){
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other){
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << "FragTrap operator called" << std::endl;
	return *this;
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void){
	std::cout << "FragTrap " <<_name << " requested kindly a High Five!" << std::endl;
}
