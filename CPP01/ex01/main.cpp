#include "Zombie.hpp"

int main()
{
	Zombie *Horde;
	Horde = zombieHorde(2, "Brainz");
	delete [] Horde;
}