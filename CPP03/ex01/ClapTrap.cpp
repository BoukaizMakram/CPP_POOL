#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : Name("Default"), HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
	std::cout << "Claptrap Default's constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : Name(name), HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
	std::cout << "ClapTrap " << this->Name << "'s Construct called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap " << other.Name << "'s copy asignement operator called" << std::endl;
	this->AttackDamage	= other.AttackDamage;
	this->EnergyPoints	= other.EnergyPoints;
	this->HitPoints		= other.HitPoints;
	this->Name			= other.Name;
	return (*this);
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "ClapTrap " << other.Name << "'s copy constructor called" << std::endl;
	*this = other;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->Name << "'s Destructor called" << std::endl;
}


void	ClapTrap::attack(const std::string& target)
{
	std::cout << "\033[34m";
	if (this->EnergyPoints > 0 && this->HitPoints > 0)
	{
		std::cout << "ClapTrap " << this->Name << " attacks " << target << " causing " << this->AttackDamage << " points of damage!" << std::endl;
		this->EnergyPoints--;
	}
	else if (this->EnergyPoints == 0)
	{
		std::cout << this->Name << " Tried to attack " << target << " but has no energy points" << std::endl;
	}
	else
	{
		std::cout << this->Name << " Tried to attack " << target << " but has no hit points" << std::endl;
	}
	std::cout << "\033[0m";
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "\033[33m";
	if (this->HitPoints > amount)
	{
		HitPoints -= amount;
	}
	else if (this->HitPoints > 0)
	{
		HitPoints = 0;
	}
	else if (this->HitPoints == 0)
	{
		std::cout << "\033[31mClapTrap " << this->Name << " is already dead!\033[0m" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->Name << " took damage and lost " << amount << " Hit Points and now has " << this->HitPoints << " Hit Points." << std::endl;
	std::cout << "\033[0m";
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "\033[32m";
	if (this->EnergyPoints > 0 && this->HitPoints > 0 && this->HitPoints + amount <= 10)
	{
		this->HitPoints += amount;
		std::cout << "ClapTrap " << this->Name << " repaired itself and has gained " << amount << " and now has " << this->HitPoints << " Hit Points" << std::endl;
		this->EnergyPoints--;
	}
	else if (this->EnergyPoints == 0)
	{
		std::cout << "ClapTrap " << this->Name << " tried to repair itself, but he have no Energy Points." << std::endl;
	}
	else if (this->HitPoints == 0)
	{
		std::cout << "ClapTrap " << this->Name << " tried to repair itself, but he have no Hit Points." << std::endl;
	}
	else if (this->HitPoints + amount > 10)
	{
		std::cout << "ClapTrap " << this->Name << "Can't be repaired to have more than 10 Hit Points." << std::endl;
	}
	std::cout << "\033[0m";
}

void	ClapTrap::setDamage(unsigned int attack_damage)
{
	this->AttackDamage = attack_damage;
}
