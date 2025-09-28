#include "Character.hpp"

Character::Character(): _name("default"), _floorItemsIndex(0){
	for (int i = 0; i < 4; i++) _inventory[i] = nullptr;
    for (int i = 0; i < 100; i++) _floorItems[i] = nullptr;
}

Character::Character(const std::string& name): _name(name), _floorItemsIndex(0){
	for (int i = 0; i < 4; i++) _inventory[i] = nullptr;
    for (int i = 0; i < 100; i++) _floorItems[i] = nullptr;
}

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
	for (int i = 0; i < _floorItemsIndex; i++)
		delete _floorItems[i];
}

std::string const & Character::getName() const{
	return _name;
}

void Character::equip(AMateria* m){
	if (!m)
		return;
	for (int i = 0; i <  4; i++)
		if (_inventory[i] == nullptr){
			_inventory[i] = m;
			return ;
		}
}

void Character::unequip(int idx){
	if (idx < 0 || idx >= 4 || !_inventory[idx])
		return;
	if (_floorItemsIndex < 100)
		_floorItems[_floorItemsIndex++] = _inventory[idx];
	_inventory[idx] = nullptr;
}

void Character::use(int idx, ICharacter& target){
	if (idx < 0 || idx >=4 || !_inventory[idx])
		return;
	_inventory[idx]->use(target);
}