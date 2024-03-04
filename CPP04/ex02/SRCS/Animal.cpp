#include "../HDRS/Animal.hpp"

Animal :: Animal()
{
	std::cout << "Animal Constructor Called" << std::endl;
}

Animal :: Animal(const Animal &other)
{
	*this = other;
	std::cout << "Animal Copy Constructor Called" << std::endl;
}

Animal& Animal::operator=(const Animal &other)
{
	if (this != &other)
		this->type = other.type;
	return (*this);
}

Animal :: ~Animal()
{
	std::cout << "Animal Destructor Called" << std::endl;
}

void	Animal::makeSound() const
{
	std::cout << "Animal Sound" << std::endl;
}


std::string	Animal::getType() const
{
	return (this->type);
}