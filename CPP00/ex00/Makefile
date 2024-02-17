CPP			= c++
CPPFLAGS	= -Wall -Wextra -Werror
SRCS		= megaphone.cpp
NAME		= megaphone

all : $(NAME)

$(NAME) : $(SRCS) $(OBJS)
	$(CPP) $(CPPFLAGS) $(SRCS) -o $(NAME)

clean :

fclean : clean
	rm -rf $(NAME)

re : fclean all