#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name"), _name("default"){
	_hitPoints = 100;    // FragTrap hit points
	_energyPoints = 50;  // ScavTrap energy points  
	_attackDamage = 30;  // FragTrap attack damage
	std::cout << "DiamondTrap default constructor called\n";
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), _name(name){
	_hitPoints = 100;    // FragTrap hit points
	_energyPoints = 50;  // ScavTrap energy points
	_attackDamage = 30;  // FragTrap attack damage
	std::cout << "DiamondTrap constructor called\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other), _name(other._name){
	_hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
	std::cout << "DiamondTrap copy constructor called\n";
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other){
	if (this != &other){
		ClapTrap::operator=(other);
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
	}
	std::cout << "DiamondTrap copy assignment operator called\n";
	return *this;
}

DiamondTrap::~DiamondTrap(){
	std::cout << "DiamondTrap destructor called\n";
}

void DiamondTrap::attack(const std::string& target){
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(){
	std::cout << "I am " << _name << " but also known as " << ClapTrap::_name << std::endl;
}