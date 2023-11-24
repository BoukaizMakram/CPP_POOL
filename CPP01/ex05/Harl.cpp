#include "Harl.hpp"

void	Harl::debug( void )
{
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
}

void	Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I’ve been coming here for years and you just started working here last month." << std::endl;
}

void	Harl::error( void )
{
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}


void	Harl::complain( std::string level )
{
	void (Harl::*fct[4])();
	fct[0] = &Harl::debug;
	fct[1] = &Harl::info;
	fct[2] = &Harl::warning;
	fct[3] = &Harl::error;

	std::string message[4] = {"debug", "info", "warning", "error"};
	for (int i = 0; i < 4; i++)
	{
		if (message[i] == level)
			(this->*(fct[i]))();
	}
}