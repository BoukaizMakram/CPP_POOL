#include "ScavTrap.hpp"

int main()
{
	ScavTrap		Costa("Costa");
	ScavTrap		Romero("Romero");
	unsigned int	attackDamage = 2;
	unsigned int	repairAmount = 1;

	Costa.setDamage(attackDamage);
	Romero.setDamage(attackDamage);
	for (int i = 1; i <= 10; i++)
	{
		Costa.attack("Romero");
		Romero.takeDamage(attackDamage);
		Romero.beRepaired(repairAmount);
		Romero.attack("Costa");
		Costa.takeDamage(attackDamage);
		Costa.beRepaired(repairAmount);
	}
}