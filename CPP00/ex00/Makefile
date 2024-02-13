CPP			= c++
CPPFLAGS	= -Wall -Wextra
SRCS		= megaphone.cpp
OBJS		= $(SRCS:.cpp=.o)
NAME		= megaphone

all : $(NAME)

$(NAME) : $(SRCS) $(OBJS)
	$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJS)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all