#include "../HDRS/Dog.hpp"

Dog::Dog()
{
	this->brain = new Brain();
	this->type = "Dog";
	std::cout << "Dog Constructor Called" << std::endl;
}

Dog::~Dog()
{
	delete(this->brain);
	std::cout << "Dog Destructor Called" << std::endl;
}

void	Dog::makeSound()
{
	std::cout << "Dog    Barks" << std::endl;
}