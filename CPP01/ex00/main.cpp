#include "Zombie.hpp"

int	main()
{
	Zombie stack_zombie("Stack");
	Zombie *heap_Zombie = newZombie("Heap");

	randomChump("Random");
	delete heap_Zombie;
	return (0);
}