#include "Character.hpp"

Character::Character(): _name("default"){}

Character::Character(const std::string& name): _name(name){}

Character::Character(const Character& other) :_name(other._name){
	for (int i = 0; i < 4; i++){
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = nullptr;
	}
}

Character& Character::operator=(const Character& other){
	if (this != &other){
		_name = other._name;
		for (int i = 0; i < 4; i++){
			delete _inventory[i];
			if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
			else
			_inventory[i] = nullptr; 
		}
	}
	return *this;
}

Character::~Character(){
	for (int i = 0; i < 4; i++)
		delete _inventory[i];
}

std::string const & Character::getName() const{
	return _name;
}

void Character::equip(AMateria* m){}

void Character::unequip(int idx){}

void Character::use(int idx, ICharacter& target){}