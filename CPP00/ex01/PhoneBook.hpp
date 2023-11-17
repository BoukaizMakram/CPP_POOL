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
