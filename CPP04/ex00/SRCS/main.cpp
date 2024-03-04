#include "../HDRS/Cat.hpp"
#include "../HDRS/Dog.hpp"
#include "../HDRS/WrongCat.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define BLUE	"\033[34m"
#define YELLOW  "\033[33m"

int main() {
    Animal *meta = new Animal();
    Animal *dog = new Dog();
    Animal *cat = new Cat();

    WrongAnimal *wrongMeta = new WrongAnimal();
    WrongAnimal *wrongCat = new WrongAnimal();

	std::cout << GREEN;
    std::cout << "Animal 1 is : " << cat->getType() << " " << std::endl;
    std::cout << "Animal 2 is : " << dog->getType() << " " << std::endl;

	std::cout << BLUE;
    meta->makeSound();
    cat->makeSound();
    dog->makeSound();

	std::cout << RED;
    wrongMeta->makeSound();
    wrongCat->makeSound();
    std::cout << "The last two seem to be indistinguishable." << std::endl;

	std::cout << RESET;
    delete meta;
    delete dog;
    delete cat;
    delete wrongMeta;
    delete wrongCat;

    return 0;
}