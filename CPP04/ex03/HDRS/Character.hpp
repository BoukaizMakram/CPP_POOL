#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include <iostream>

class Character : public ICharacter
{
	private:
		std::string	Name;
		AMateria*	inventory[4];
	public:
		Character();
		Character(const Character& other);
		~Character();

		Character&			operator=( const Character& other );
		void				use(int index, ICharacter &target );
		void				equip( AMateria *materia );
		void				unequip( int index );
		std::string const&	getName() const;
};

#endif