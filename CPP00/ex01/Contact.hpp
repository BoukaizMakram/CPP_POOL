#ifndef CONTACT_HPP
# define CONTACT_HPP

class	Contact
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
	public:
		Contact();
		void	set_contact_info();
		void	display_contacts(int index, int mode);
};
#endif
