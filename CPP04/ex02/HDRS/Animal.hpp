#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "Brain.hpp"
#include <iostream>

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(const Animal &other);
		virtual ~Animal();

		Animal& operator=(const Animal &other);
		virtual void			makeSound( void ) const = 0;
		virtual std::string		getType  ( void ) const;
};

#endif