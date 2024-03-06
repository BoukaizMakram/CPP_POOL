#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		Cure(const Cure &other);
		~Cure();

		AMateria*	clone() const;
		void		use(ICharacter& target);
		Cure&		operator=(const Cure &other);
};

#endif