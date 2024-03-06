#include "../HDRS/Cure.hpp"

Cure::Cure()
{
	this->Type = "cure";
}

Cure::Cure(const Cure &other)
{
	this->Type = "cure";
	*this = other;
}

Cure::~Cure() {}

Cure& Cure::operator=(const Cure &other)
{
	this->Type = other.Type;
	return (*this);
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}

AMateria* Cure::clone() const
{
	AMateria *cloned = new Cure(*this);
	return (cloned);
}