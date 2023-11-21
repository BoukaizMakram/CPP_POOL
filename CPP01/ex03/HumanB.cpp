#include "HumanB.hpp"

void	HumanB::attack()
{
	if (this->_weapon)
	{
		std::cout << this->_name << " attacks with his "
				<< (*(this->_weapon)).getType() << std::endl;
	}
	else
	{
		std::cout << this->_name << " tries to attack but has no weapon "
					<< std::endl;
	}
}

void	HumanB::set_weapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

HumanB::HumanB(std::string name) : _name(name)
{
	this->_weapon = NULL;
}

HumanB::~HumanB() {}