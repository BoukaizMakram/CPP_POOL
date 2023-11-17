#include <iostream>

class User
{
	private:
		std::string first_name;
		std::string last_name;
		int			salary;
	public:
		User();
		int	get_salary();
		std::string	getinfo(int mode) const;
		~User();
};

User::User() : first_name ("Makram"), last_name ("Boukaiz"), salary (50000) {}
User::~User()
{
	std::cout << "I hope you had fun :)" << std::endl;
}

int User::get_salary()
{
	last_name = "Hello world";
	return (salary);
}

std::string	User::getinfo(int mode) const
{
	if (mode == 1)
		return (first_name);
	else if (mode == 2)
		return (last_name);
	return (last_name);
}

int	main()
{
	User user;
	User user2;
	std::cout << user.get_salary() << std::endl;
	std::cout << "| fistName : " << user.getinfo(1) << " | last name : " << user.getinfo(2) << std::endl;
	return (0);
}
