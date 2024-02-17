#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>

class Zombie
{
	private:
		std::string name;
	public:
		Zombie();
		void 	announce( void );
		void	setname( std::string name );
		~Zombie();
};

Zombie*	zombieHorde( int N, std::string name );

#endif