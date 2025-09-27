#pragma once
#include "ICharacter.hpp"
#include <iostream>

class AMateria{

	protected:


	public:
		AMateria();
		AMateria(std::string const & type);
		AMateria(const AMateria& other);
		~AMateria();

		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};
