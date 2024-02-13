/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukaiz <mboukaiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:58:52 by mboukaiz          #+#    #+#             */
/*   Updated: 2024/02/13 15:14:05 by mboukaiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact():first_name(""), last_name(""),phone_number(""), darkest_secret("") {}

void	Contact::set_contact_info()
{
	if (!std::cin)
		exit (1);
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
        std::cout << "first name: " << first_name << std::endl;
        std::cout << "last name: " << last_name << std::endl;
        std::cout << "nickname: " << nickname << std::endl;
        std::cout << "phone number: " << phone_number << std::endl;
        std::cout << "darkest secret: " << darkest_secret << std::endl;
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