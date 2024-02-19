CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
HEADER = HumanA.hpp HumanB.hpp Weapon.hpp
NAME = ex03

all : $(NAME)

$(NAME) : $(SRC) $(HEADER)
	$(CPP) $(SRC) $(CPPFLAGS) -o $(NAME)

clean :
	rm -rf $(NAME)

fclean : clean

re : fclean all