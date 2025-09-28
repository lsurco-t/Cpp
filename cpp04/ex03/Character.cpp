#include "Character.hpp"

Character::Character():_name("default"){}

Character::Character(const Character& other){}

Character& Character::operator=(const Character& other){}

Character::~Character(){}

std::string const & Character::getName() const{}

void Character::equip(AMateria* m){}

void Character::unequip(int idx){}

void Character::use(int idx, ICharacter& target){}