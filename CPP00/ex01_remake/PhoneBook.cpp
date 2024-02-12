#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

PhoneBook::PhoneBook()
{
	current_contact = 0;
}

void	insert_input(std::string message, std::string &data)
{
	data = "";
	while (data == "")
	{
		std::cout << message;
		std::getline(std::cin, data);
	}
}

void	Contact::set_infos()
{
	insert_input("First Name: ", first_name);
}

void	Contact::get_contact_infos()
{
	std::cout << first_name;
}

void	PhoneBook::get_phonebook_infos()
{
	for (int i = 0; i <= current_contact; i++)
		contacts[i].get_contact_infos();
}

void	PhoneBook::add_contact()
{
	current_contact++;
	if (current_contact == 9)
		current_contact = 0;
	contacts[current_contact].set_infos();
}

int main()
{
	PhoneBook	phone;
	std::string command;

	command = "";
	while (1)
	{
		std::cout << "Please enter one of the following three commands : ADD, SEARCH and EXIT" << std::endl;
		std::getline(std::cin, command);
		if (command == "ADD")
		{
			phone.add_contact();
		}
		if (command == "SEARCH")
		{
			phone.get_phonebook_infos();
		}
		if (command == "EXIT")
		{
			std::cout << "EXIT" << std::endl;
			break;
		}
	}
}