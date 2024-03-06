#include "../HDRS/Ice.hpp"

Ice::Ice()
{
	this->Type = "ice";
}

Ice::Ice(const Ice &other)
{
	this->Type = "ice";
	(*this) = other;
}

Ice::~Ice() {}

Ice& Ice::operator=(const Ice &other)
{
	this->Type = other.Type;
	return (*this);
}

void	Ice::use(ICharacter &target)
{
	 std::cout << "* shoots an ice bolt at " << target.getName() << " *"  << std::endl;
}

AMateria*	Ice::clone() const
{
	AMateria* cloned = new Ice(*this);
	return (cloned);
}