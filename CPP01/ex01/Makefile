CXX = c++
CXXFLAGS = -Wall -Wextra -std=c++98
CPPFLAGS = -Iinclude

SRC = main.cpp zombieHorde.cpp Zombie.cpp
HEADER = Zombie.hpp
NAME = Horde

all : $(NAME)

$(NAME) : $(SRC) $(HEADER)
	$(CXX) $(SRC) -o $(NAME)

clean :
	rm -rf $(NAME)

fclean : clean

re : fclean all