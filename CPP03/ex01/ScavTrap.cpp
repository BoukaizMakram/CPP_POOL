#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->HitPoints = 100;
	this->EnergyPoints = 50;
	this->AttackDamage = 20;
}

ScavTrap::ScavTrap() 
{
	ClapTrap();
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->Name << " Destructed" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->Name << " is now in Gate keeper mode" << std::endl;
}