#include "../HDRS/AMateria.hpp"

AMateria::AMateria()
{

}

AMateria::AMateria(const AMateria &other)
{
	*this = other;
}

AMateria::~AMateria() {}

AMateria& AMateria::operator=(const AMateria &other)
{
	this->Type = other.Type;
	return (*this);
}