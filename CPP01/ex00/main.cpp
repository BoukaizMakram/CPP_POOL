#include "Zombie.hpp"

int	main()
{
	Zombie stack_zombie("Stack");
	Zombie *heap_Zombie = newZombie("Heap");

	stack_zombie.announce();
	heap_Zombie->announce();
	randomChump("Random");
	delete heap_Zombie;
}
