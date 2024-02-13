/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukaiz <mboukaiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:12:37 by mboukaiz          #+#    #+#             */
/*   Updated: 2024/02/13 15:08:26 by mboukaiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"

class	PhoneBook
{
	private:
		Contact	contacts[8];
		int		current_contact;
		int		display_index;
		int		max_contacts;
	public:
		PhoneBook();
		void	add_contact();
		void	search_contact();
};
#endif
