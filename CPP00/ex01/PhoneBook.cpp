/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukaiz <mboukaiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:12:31 by mboukaiz          #+#    #+#             */
/*   Updated: 2024/02/13 15:15:24 by mboukaiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook():current_contact(0), display_index(0), max_contacts(2) {}

void	PhoneBook::search_contact()
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
				exit (1);
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
		{
			std::cout << "Contact list is empty" << std::endl << std::endl;
			return ;
		}
	}
}


void	PhoneBook::add_contact()
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
