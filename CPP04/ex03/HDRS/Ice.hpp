#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		Ice(const Ice &other);
		~Ice();

		Ice&		operator=(const Ice &other);
		void		use(ICharacter& other);
		AMateria*	clone() const;
};

#endif
