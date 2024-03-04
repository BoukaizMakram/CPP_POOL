#include "../HDRS/WrongAnimal.hpp"

WrongAnimal :: WrongAnimal()
{
	std::cout << "WrongAnimal Constructor Called" << std::endl;
}

WrongAnimal :: WrongAnimal(const WrongAnimal &other)
{
	*this = other;
	std::cout << "WrongAnimal Copy Constructor Called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
		this->type = other.type;
	return (*this);
}

WrongAnimal :: ~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor Called" << std::endl;
}

void	WrongAnimal::makeSound()
{
	std::cout << "WrongAnimal make a sound" << std::endl;
}


std::string	WrongAnimal::getType() const
{
	return (this->type);
}