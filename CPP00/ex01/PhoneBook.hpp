/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukaiz <mboukaiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:12:37 by mboukaiz          #+#    #+#             */
/*   Updated: 2024/02/11 15:13:57 by mboukaiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"

class	Phone_Book
{
	private:
		Contact	contacts[8];
		int		current_contact;
		int		display_index;
		int		max_contacts;
	public:
		Phone_Book();
		void	add_contact();
		void	search_contact();
};
#endif
