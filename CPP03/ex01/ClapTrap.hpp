#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	protected:
		std::string		Name;
		unsigned int	HitPoints;
		unsigned int	EnergyPoints;
		unsigned int	AttackDamage;
	public:
		ClapTrap();
		ClapTrap(const ClapTrap &other);
		ClapTrap(std::string name);
		~ClapTrap();
		ClapTrap&	operator=(const ClapTrap& other);
		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		void		setDamage(unsigned int	attack_damage);
};

#endif