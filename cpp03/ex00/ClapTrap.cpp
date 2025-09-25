#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0){
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0){
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap (const ClapTrap& other) 
	: _name(other._name), 
	_hitPoints(other._hitPoints), 
	_energyPoints(other._energyPoints),
	_attackDamage(other._attackDamage) {

	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other){
	if (this != &other){
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	std::cout << "Copy assigment operator called" << std::endl;
	return *this;
}

ClapTrap::~ClapTrap(){
	std::cout << "Destructor called\n";
}

void ClapTrap::attack(const std::string& target){
	if (_energyPoints == 0 || _hitPoints == 0){
		std::cout << "ClapTrap " << _name << " cannot attack (no hit points or energy left)." << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
	if (_hitPoints == 0) {
		std::cout << "ClapTrap " << _name << " is destroyed already :(" << std::endl;
		return ;
	}
	if (amount >= _hitPoints){
		_hitPoints = 0;
		std::cout << "ClapTrap " << _name << " took " << amount << " damage and got destroyed!" << std::endl;
	}
	else if (amount < _hitPoints){
		_hitPoints -= amount;
		std::cout << "ClapTrap " << _name << " took " << amount << " damage and have "<< _hitPoints << " hp points left" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount){
	if (_energyPoints == 0 || _hitPoints == 0){
		std::cout << "ClapTrap " << _name << " cannot repair (no hit points or energy left)." << std::endl;
		return ;
	}
	_hitPoints += amount;
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " repaired itself for " << amount << ", and have " << _hitPoints << " points of hp" << std::endl;
}