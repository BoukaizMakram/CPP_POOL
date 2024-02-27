NAME 		= ex00
HDRS 		= ClapTrap.hpp
SRCS 		= ClapTrap.cpp main.cpp
CPP			= c++
CPPFLAGS	= -Wall -Wextra -Werror

all  : $(NAME)

$(NAME) : $(HDRS) $(SRCS)
	$(CPP) $(CPPFLAGS) $(SRCS) -o $(NAME)

fclean : 
	rm -rf $(NAME)

clean : 
	rm -rf $(NAME)