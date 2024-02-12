/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukaiz <mboukaiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:12:31 by mboukaiz          #+#    #+#             */
/*   Updated: 2024/02/12 18:27:21 by mboukaiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "PhoneBook.hpp"
#include "Contact.hpp"

Contact::Contact():first_name(""), last_name(""),phone_number(""), darkest_secret("") {}
Phone_Book::Phone_Book():current_contact(0), display_index(0), max_contacts(2) {}

void	avoid_repition(std::string message, std::string &data, bool phone)
{
	data = "";
	while (data == "")
	{
		std::cout << message;
		getline(std::cin, data);
		if (!std::cin)
			exit (0);
		if (phone)
		{
			for (int i = 0; i < data.length(); i++)
			{
				if (!isdigit(data[i]))
				{
					data = "";
					std::cout << "Please enter a valid phone number, digits only!" << std::endl;
				}
			}
		}
	}
}

void	Contact::set_contact_info()
{
	if (!std::cin)
		exit (0);
	avoid_repition("Enter First Name: ", first_name, false);
	avoid_repition("Enter Last Name: ", last_name, false);
	avoid_repition("Enter Nick Name: ", nickname, false);
	avoid_repition("Enter Phone Number: ", phone_number, true);
	avoid_repition("Enter Darkest Secret: ", darkest_secret, false);
}

void	Contact::display_contacts(int index, int mode)
{
	if (mode)
	{
		std::cout << std::setw(10) << index + 1 << "|"
					<< std::setw(10) << (first_name.length() > 10 ? first_name.substr(0, 9) + "." : first_name) << "|"
					<< std::setw(10) << (last_name.length() > 10 ? last_name.substr(0, 9) + "." : last_name) << "|"
					<< std::setw(10) << (nickname.length() > 10 ? nickname.substr(0, 9) + "." : nickname) << "|"
					<< std::setw(10) << (phone_number.length() > 10 ? phone_number.substr(0, 9) + "." : phone_number) << "|"
					<< std::setw(10) << (darkest_secret.length() > 10 ? darkest_secret.substr(0, 9) + "." : darkest_secret) << "|"
					<< std::endl;
	}
	else
	{
		std::cout << std::setw(10) << index + 1 << "|"
				<< std::setw(10) << (first_name.length() > 10 ? first_name.substr(0, 9) + "." : first_name) << "|"
				<< std::setw(10) << (last_name.length() > 10 ? last_name.substr(0, 9) + "." : last_name) << "|"
				<< std::setw(10) << (nickname.length() > 10 ? nickname.substr(0, 9) + "." : nickname) << "|"
				<< std::endl;
	}
}

void	display_table(int mode)
{
	std::cout << std::endl;
	if (mode)
	{
		std::cout << std::setw(10) << "Index" << "|"
				<< std::setw(10) << "First Name" << "|"
				<< std::setw(10) << "Last Name" << "|"
				<< std::setw(10) << "Nickname" << "|"
				<< std::setw(10) << "Phone" << "|"
				<< std::setw(10) << "Secret" << "|"
				<< std::endl;
	}
	else
	{
		std::cout << std::setw(10) << "Index" << "|"
				<< std::setw(10) << "First Name" << "|"
				<< std::setw(10) << "Last Name" << "|"
				<< std::setw(10) << "Nickname" << "|"
				<< std::endl;
	}
}

void	Phone_Book::search_contact()
{
	int		i = 0;
	bool	index_printed = false;

	if (display_index > 0)
		display_table(0);
	while (i < display_index)
	{
		contacts[i].display_contacts(i, 0);
		i++;
	}
	std::cout << std::endl;
	while (index_printed == false)
	{
		if (display_index > 0)
		{
			std::cout << "Enter the index of the contact you want to display: ";
			int index;
			std::cin >> index;
			if (!std::cin)
				return ;
			std::cin.ignore();
			if (index <= display_index && index > 0)
			{
				display_table(1);
				contacts[index - 1].display_contacts(index - 1, 1);
				std::cout << std::endl;
				index_printed = true;
			}
			else
				std::cout << "Index out of range!" << std::endl;
		}
		else
			std::cout << "Contact list is empty" << std::endl << std::endl;
	}
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
		if (!std::cin)
			exit(0) ;
		std::cout << "Enter command (ADD, SEARCH, EXIT): " << std::endl;
		getline(std::cin, command);
		// std::cin.ignore();
		if (!std::cin)
			exit(0) ;
		if (command == "ADD")
		{
			phone_book.add_contact();
		}
		else if (command == "SEARCH")
		{
			phone_book.search_contact();
		}
		else if (command == "EXIT")
		{
			std::cout << "EXIT" << std::endl;
			break;
		}
	}
	return (0);
}