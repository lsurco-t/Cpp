#pragma once
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource{

	public:
		MateriaSource();
		MateriaSource(const MateriaSource& other);
		MateriaSource& operator=(const MateriaSource other);
		~MateriaSource();

		void learnMateria(AMateria*);
		void createMateria(std::string const &);
};