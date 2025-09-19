#include "Zombie.hpp"

Zombie::Zombie(){}

Zombie::~Zombie(){
	std::cout << "Zombie " << _name << " got destroyed\n";  
}

void Zombie::setZombieName(const std::string& zombieName){
	 _name = zombieName;
}

void Zombie::announce(){
	std::cout << "\033[31m" << _name << ": BraiiiiiiinnnzzzZ...\033[0m" << std::endl;
}

