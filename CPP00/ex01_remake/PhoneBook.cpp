#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

PhoneBook::PhoneBook()
{
	current_contact = 0;
}

void	Contact::set_infos()
{
	std::string data;
	data = "";
	while (data == "")
	{
		std::cout << "Enter first name : " << 1;
		getline(std::cin, data);
	}
	first_name = data;
}

void	Contact::get_contact_infos()
{
	std::cout << first_name << std::endl;
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
	std::cout << current_contact << std::endl;
}

int main()
{
	PhoneBook	phone;
	std::string command;

	command = "";
	while (command != "EXIT")
	{
		std::cout << "Please enter one of the following three commands : ADD, SEARCH and EXIT" << std::endl;
		std::cin >> command;
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
		}
	}
}