#include "../HDRS/Character.hpp"

Character::Character()
{

}

Character::Character(const Character &other)
{

}

Character::~Character()
{

}

Character& Character::operator=(const Character& other)
{

}

void	Character::use(int index, ICharacter &target)
{

}

void	Character::equip(AMateria* materia)
{

}

void	Character::unequip(int index)
{

}

std::string const & Character::getName() const
{
	return (this->Name);
}
