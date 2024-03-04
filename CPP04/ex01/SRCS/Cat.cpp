#include "../HDRS/Cat.hpp"

Cat::Cat()
{
	this->brain = new Brain();
	this->type = "Cat";
	std::cout << "Cat Constructor Called" << std::endl;
}

Cat::~Cat()
{
	delete(this->brain);
	std::cout << "Cat Destructor Called" << std::endl;
}

void	Cat::makeSound()
{
	std::cout << "Cat    Meows" << std::endl;
}