CXX = c++
CXXFLAGS = -Wall -Wextra -std=c++98
CPPFLAGS = -Iinclude

SRC = main.cpp newZombie.cpp randomChump.cpp Zombie.cpp
HEADER = Zombie.hpp
NAME = Zombie

all : $(NAME)

$(NAME) : $(SRC) $(HEADER)
	$(CXX) $(SRC) -o $(NAME)

clean :
	rm -rf $(NAME)

fclean : clean

re : fclean all