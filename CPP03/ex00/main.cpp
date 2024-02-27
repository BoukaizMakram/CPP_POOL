#include "ClapTrap.hpp"

int main()
{
	ClapTrap Khabib("Khabib");
	ClapTrap Mcgregor ("Mcgregor");

	for (int i = 1; i <= 10; i++)
	{
		Khabib.attack("Mcgregor");
		Mcgregor.takeDamage(2);
		Mcgregor.beRepaired(1);
		Mcgregor.attack("Khabib");
		Khabib.takeDamage(2);
		Khabib.beRepaired(1);
	}
}