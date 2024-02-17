#include <iostream>

class Weapon
{
	private:
		std::string type;
	public:
		const std::string	&getType() const;
		void				setType( std::string type );
		Weapon(std::string type);
};

Weapon::Weapon(std::string type) : type(type) {}

void	Weapon::setType( std::string type )
{
	this->type = type;
}

const std::string	&Weapon::getType() const
{
	return (this->type);
}

class HumanA
{
	private:
		Weapon		&weapon;
		std::string	name;
	public:
		void		attack();
		HumanA( std::string name, Weapon &weapon );
};

HumanA::HumanA( std::string name, Weapon &weapon ) : name(name), weapon(weapon) {}

class HumanB
{
	private:
		Weapon		*weapon;
		std::string	name;
	public:
		void		attack();
		void		setWeapon(Weapon &weapon);
		HumanB( std::string name );
};

void		HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

void	HumanA::attack()
{
	std::cout << this->name << " attacks with their " 
				<< this->weapon.getType() << std::endl;
}

void	HumanB::attack()
{
	if (this->weapon)
		std::cout << this->name << " attacks with their " 
					<< this->weapon->getType() << std::endl;
	else
		std::cout << this->name << " can't attack because he is a pussy "
					<< std::endl;
}

HumanB::HumanB( std::string name )
{
	this->name = name;
	this->weapon = NULL;
}

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA Ridwane("Ridwane", club);
		Ridwane.attack();
		club.setType("some other type of club");
		Ridwane.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB Makram("Makram");
		Makram.setWeapon(club);
		Makram.attack();
		club.setType("some other type of club");
		Makram.attack();
	}
	return (0);
}
