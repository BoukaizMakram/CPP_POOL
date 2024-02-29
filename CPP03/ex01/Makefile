NAME 		= ex01
HDRS 		= ClapTrap.hpp
SRCS 		= ClapTrap.cpp main.cpp ScavTrap.cpp ScavTrap.hpp
CPP			= c++
CPPFLAGS	= -Wall -Wextra -Werror

all  : $(NAME)

$(NAME) : $(HDRS) $(SRCS)
	$(CPP) $(CPPFLAGS) $(SRCS) -o $(NAME)

fclean : 
	rm -rf $(NAME)

clean : 
	rm -rf $(NAME)

re : clean all