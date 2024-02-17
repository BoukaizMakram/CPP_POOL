CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
CPPFLAGS = -Iinclude

SRC = main.cpp zombieHorde.cpp Zombie.cpp
HEADER = Zombie.hpp
NAME = Horde

all : $(NAME)

$(NAME) : $(SRC) $(HEADER)
	$(CPP) $(SRC) -o $(NAME)

clean :
	rm -rf $(NAME)

fclean : clean

re : fclean all