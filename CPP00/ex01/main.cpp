/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukaiz <mboukaiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:02:19 by mboukaiz          #+#    #+#             */
/*   Updated: 2024/02/13 15:14:56 by mboukaiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	avoid_repition(std::string message, std::string &data, bool phone)
{
	data = "";
	while (data == "")
	{
		std::cout << message;
		getline(std::cin, data);
		if (!std::cin)
			exit (1);
		if (phone)
		{
			for (size_t i = 0; i < data.length(); i++)
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

void	display_table(int mode)
{
	std::cout << std::endl;
	if (!mode)
	{
		std::cout << std::setw(10) << "Index" << "|"
				<< std::setw(10) << "First Name" << "|"
				<< std::setw(10) << "Last Name" << "|"
				<< std::setw(10) << "Nickname" << "|"
				<< std::endl;
	}
}

int	main()
{
	PhoneBook PhoneBook;
	std::string	command;

	while (1)
	{
		if (!std::cin)
			return (1);
		std::cout << "Enter command (ADD, SEARCH, EXIT): " << std::endl;
		getline(std::cin, command);
		if (command == "ADD")
		{
			PhoneBook.add_contact();
		}
		else if (command == "SEARCH")
		{
			PhoneBook.search_contact();
		}
		else if (command == "EXIT")
		{
			std::cout << "Good bye :)" << std::endl;
			break;
		}
	}
	return (0);
}