#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
	for (int i = 0; i < 4; i++)
		_materiaTypes[i] = nullptr;
}

MateriaSource::MateriaSource(const MateriaSource& other){
	for (int i = 0; i < 4; i++)
		if(other._materiaTypes[i])
			_materiaTypes[i] = other._materiaTypes[i]->clone();
		else
			_materiaTypes[i] = nullptr;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other){
	if (this != &other){
		for (int i = 0; i < 4; i++){
			delete _materiaTypes[i];
			if(other._materiaTypes[i])
				_materiaTypes[i] = other._materiaTypes[i]->clone();
			else
				_materiaTypes[i] = nullptr;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource(){
	for (int i = 0; i < 4; i++)
		delete _materiaTypes[i];
}

void MateriaSource::learnMateria(AMateria* m){
	for (int i = 0; i < 4; i++)
		if (_materiaTypes[i] == nullptr){
			_materiaTypes[i] = m;
			return ;
		}
}

AMateria* MateriaSource::createMateria(std::string const & type){
	for (int i = 0; i < 4; i++){
		if (_materiaTypes[i] && _materiaTypes[i]->getType() == type)
			return _materiaTypes[i]->clone();
	}
	return nullptr;
}