#include "Zombie.hpp"

int	main()
{
	int N = 5;

	Zombie *Horde = zombieHorde(N, "Horde");
	for (int i = 0; i < N; i++)
	{
		Horde[i].announce();
	}
	delete[] Horde;
	return (0);
}
