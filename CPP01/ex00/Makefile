CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp newZombie.cpp randomChump.cpp Zombie.cpp
HEADER = Zombie.hpp
NAME = Zombie

all : $(NAME)

$(NAME) : $(SRCS) $(HEADER)
	$(CPP) $(SRCS) $(CPPFLAGS) -o $(NAME)

clean :
	rm -rf $(NAME)

fclean : clean

re : fclean all