#include "Zombie.hpp"

Zombie::Zombie(){}

Zombie::~Zombie(){
	std::cout << "Zombie " << Zombie::_name << " got destroyed\n";  
}

void Zombie::setZombieName(const std::string& zombieName){
	 _name = zombieName;
}

const std::string& Zombie::getZombieName() const{
	return _name;
}

void announce(){
	std::cout << "BraiiiiiiinnnzzzZ..." << std::endl;
}

