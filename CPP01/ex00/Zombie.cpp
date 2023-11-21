#include "Zombie.hpp"

void Zombie::announce( void )
{
	std::cout << this->name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie( std::string name )
{
	this->name = name;
	announce();
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << this->name << " Died" << std::endl;
}