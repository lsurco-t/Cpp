#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){

}

ClapTrap::ClapTrap (const ClapTrap& other){

}

ClapTrap& ClapTrap::operator=(const ClapTrap& other){

}

ClapTrap::~ClapTrap(){
	std::cout << "Destructor called\n";
}

void ClapTrap::attack(const std::string& target){

}

void ClapTrap::takeDamage(unsigned int amount){

}

void ClapTrap::beRepaired(unsigned int amount){

}