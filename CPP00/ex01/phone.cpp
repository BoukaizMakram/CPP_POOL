#include "phone.hpp"

Contact::Contact():first_name(""), last_name(""),phone_number(""), darkest_secret("") {}
Phone_Book::Phone_Book():current_contact(0), display_index(0), max_contacts(8) {}


void	Contact::set_contact_info()
{
	if (!std::cin)
		return ;
	while (first_name == "")
	{
		std::cout << "Enter First Name: ";
		getline (std::cin, first_name);
		if (!std::cin)
			return ;
	}
	while (last_name == "")
	{
		std::cout << "Enter Last Name: ";
		getline (std::cin, last_name);
		if (!std::cin)
			return ;
	}
	while (nickname == "")
	{
		std::cout << "Enter Nick Name: ";
		getline (std::cin, nickname);
		if (!std::cin)
			return ;
	}
	while (phone_number == "")
	{
		std::cout << "Enter Phone Number: ";
		getline (std::cin, phone_number);
		if (!std::cin)
			return ;
	}
	while (darkest_secret == "")
	{
		std::cout << "Enter Darkest Secret: ";
		getline (std::cin, darkest_secret);
		if (!std::cin)
			return ;
	}
}

void	Contact::display_contacts(int index)
{
	std::cout << std::setw(10) << index + 1 << "|"
			  << std::setw(10) << (first_name.length() > 10 ? first_name.substr(0, 9) + "." : first_name) << "|"
			  << std::setw(10) << (last_name.length() > 10 ? last_name.substr(0, 9) + "." : last_name) << "|"
			  << std::setw(10) << (nickname.length() > 10 ? nickname.substr(0, 9) + "." : nickname) << "|"
			  << std::endl;
}

void	Phone_Book::search_contact()
{
	int i = 0;

	std::cout << std::setw(10) << "Index" << "|"
			  << std::setw(10) << "First Name" << "|"
			  << std::setw(10) << "Last Name" << "|"
			  << std::setw(10) << "Nickname" << "|"
			  << std::endl;
	while (i < display_index)
	{
		contacts[i].display_contacts(i);
		i++;
	}
	std::cout << "Enter the index of the contact you want to display: ";
	int index;
	std::cin >> index;
	if (!std::cin)
		return ;
	std::cin.ignore();

	if (index <= display_index && index > 0)
		contacts[index - 1].display_contacts(index - 1);
	else
		std::cout << "Invalid index. Please enter a valid index." << std::endl;
}


void	Phone_Book::add_contact()
{
	if (current_contact < max_contacts)
	{
		contacts[current_contact].set_contact_info();
		current_contact++;
		if (display_index < max_contacts)
			display_index++;
	}
	else
	{
		current_contact = 0;
		display_index = max_contacts;
		std::cout << "Phonebook is full. Deleting the oldest contact and adding a new one." << std::endl;
		contacts[current_contact].set_contact_info();
		current_contact++;
	}
}

int	main()
{
	Phone_Book phone_book;
	std::string	command;

	while (1)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): " << std::endl;
		std::cin >> command;
		std::cin.ignore();
		if (!std::cin)
			break ;
		// if (std::cin.eof())
			// break;
		if (command == "ADD")
		{
			phone_book.add_contact();
			if (!std::cin)
				break ;
		}
		else if (command == "SEARCH")
		{
			phone_book.search_contact();
			if (!std::cin)
				break ;
		}
		else if (command == "EXIT")
		{
			std::cout << "EXIT" << std::endl;
			if (!std::cin)
				break ;
			break;
		}
	}
	return (0);
}