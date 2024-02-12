#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[8];
		int		current_contact;
	public:
		PhoneBook();
		void	add_contact();
		void	get_phonebook_infos();
};
#endif
