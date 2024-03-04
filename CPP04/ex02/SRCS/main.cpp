#include "../HDRS/Cat.hpp"
#include "../HDRS/Dog.hpp"
#include "../HDRS/WrongCat.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define BLUE	"\033[34m"
#define YELLOW  "\033[33m"

int main()
{
	std::cout << "CREATING ANIMALS : " << GREEN << std::endl;
    Animal	*animals[5] = {new Dog(), new Dog(), new Cat(), new Cat(), NULL};
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << BLUE;
	for (int i = 0; animals[i]; i++)
	{
		animals[i]->makeSound();
	}
	i->makeSound();
	j->makeSound();
	std::cout << RESET;
	std::cout << "DELETING ANIMALS : "  << RED << std::endl;
	delete j;
	delete i;
	for (int i = 0; i < 4; i++)
		delete(animals[i]);
}