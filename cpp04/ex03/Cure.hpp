#pragma once
#include "AMateria.hpp"
#include <iostream>

class Cure {

	private:

	public:
		Cure();
		Cure(const Cure& other);
		Cure& operator=(const Cure& other);
		~Cure();

		AMateria* clone() const;

};
